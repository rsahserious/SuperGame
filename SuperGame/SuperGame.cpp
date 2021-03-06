#include "SuperGame.h"

SuperGame::SuperGame()
{
	this->window = new Engine::Window("Super Game", Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);

	this->physicsWorld = new Engine::PhysicsWorld();
	this->physicsWorld->SetGravityStrength(12.0f);

	this->terrainRenderer = new Engine::AngularTerrainRenderer(this->playerCamera->GetPosition(), 10.0f, 500.0f);

	// terrain
	//Engine::Mesh* terrainMesh = new Engine::Mesh("models/terrain.obj");
	Engine::Material* terrainMaterial = new Engine::Material("textures/grass.png");
	Engine::Object* terrain = new Engine::Object(&this->terrainRenderer->GetMesh(), terrainMaterial);
	this->objects.push_back(terrain);

	// balls
	this->boxMesh = new Engine::DynamicMesh("models/sphere.obj");
	this->bricksMaterial = new Engine::Material("textures/rocks.png");

	for (float x = 0; x < 15; x += 1)
	{
		for (float y = 0; y < 15; y += 1)
		{
			Engine::SphericalCollider* collider = new Engine::SphericalCollider(glm::vec3(0, 0, 0), 1.0f);
			Engine::DynamicObject* object = new Engine::DynamicObject(this->boxMesh, this->bricksMaterial);
			object->SetCollider(collider);
			object->GetTransform()->SetPos(glm::vec3(0.0f + (rand() % 100 / 100.0f), 20.0f + (y * 3.0f), 0.0f + (x * 3.0f) + (rand() % 100 / 100.0f)));

			this->objects.push_back(object);
			this->physicsWorld->AddObject(object);
		}
	}
	
	this->shader = new Engine::Shader("shaders/shader.vs", "shaders/shader.fs");

	this->gameState = GameState::INIT;
}

SuperGame::~SuperGame()
{
	delete this->window;
	delete this->shader;
	delete this->physicsWorld;

	while (this->objects.size())
	{
		delete this->objects.back();
		this->objects.pop_back();
	}

	delete this->bricksMaterial;
	delete this->boxMesh;

	delete this->terrainRenderer;
}

void SuperGame::Run()
{
	this->gameState = GameState::RUNNING;
	this->loop();
}

void SuperGame::loop()
{
	while (this->gameState != GameState::EXIT)
	{
		static float deltaTime = 1.0f;
		const int ticks = SDL_GetTicks();

		this->processInput();
		this->processLogic(deltaTime);
		this->drawScene();

		this->currentFPS = Engine::Utils::GetFPS();

		// Output current FPS
		static int ticks_snapshot = ticks;
		if (ticks - ticks_snapshot >= Constants::FPS_OUTPUT_INTERVAL)
		{
			std::cout << "FPS: " << (int)this->currentFPS << std::endl;
			ticks_snapshot = ticks;

			// tmp
			this->terrainRenderer->Update(this->playerCamera->GetPosition());
		}
		
		// Calculate this frame's time
		int frameTime = SDL_GetTicks() - ticks;

		// FPS limiter
		static float fpsTime = 1000.0f / Constants::FPS_LIMIT;
		if (fpsTime > frameTime)
		{
			SDL_Delay(fpsTime - frameTime);
		}

		// calculate delta time
		deltaTime = Constants::DESIRED_FPS / (1000.0f / frameTime);
		deltaTime = fmin(deltaTime, 10.0f);
	}
}

void SuperGame::processInput()
{
	SDL_Event event;

	static bool isDownW = false, isDownS = false, isDownA = false, isDownD = false;
	static bool isDownShift = false;

	while (SDL_PollEvent(&event))
	{
		SDL_Keycode* keyCode = &event.key.keysym.sym;

		switch (event.type)
		{
		case SDL_QUIT:
			this->gameState = GameState::EXIT;
			break;

		case SDL_KEYDOWN:
			switch (*keyCode)
			{
			case SDLK_ESCAPE:
				this->gameState = GameState::EXIT;
				break;
			/*case SDLK_1: this->objects[0]->GetMaterial()->SetAnisotropyLevel(1); break;
			case SDLK_2: this->objects[0]->GetMaterial()->SetAnisotropyLevel(2); break;
			case SDLK_3: this->objects[0]->GetMaterial()->SetAnisotropyLevel(4); break;
			case SDLK_4: this->objects[0]->GetMaterial()->SetAnisotropyLevel(8); break;
			case SDLK_5: this->objects[0]->GetMaterial()->SetAnisotropyLevel(16); break;*/
			default:
				this->inputManager->UpdateKey(*keyCode, true);
			}
			break;

		case SDL_KEYUP:
			switch (*keyCode)
			{
			default:
				this->inputManager->UpdateKey(*keyCode, false);
			}
			break;

		case SDL_MOUSEMOTION:
			this->playerCamera->UpdateEyeDirection(event.motion.xrel, event.motion.yrel);
			break;
		}
	}
}

void SuperGame::processLogic(float deltaTime)
{
	this->angle += 0.01;

	if (this->inputManager->IsKeyDown(SDLK_w))
	{
		this->player->ExecuteAction(PlayerAction::MOVE_FORWARD, deltaTime);
	}

	if (this->inputManager->IsKeyDown(SDLK_s))
	{
		this->player->ExecuteAction(PlayerAction::MOVE_BACKWARD, deltaTime);
	}

	if (this->inputManager->IsKeyDown(SDLK_a))
	{
		this->player->ExecuteAction(PlayerAction::MOVE_LEFT, deltaTime);
	}

	if (this->inputManager->IsKeyDown(SDLK_d))
	{
		this->player->ExecuteAction(PlayerAction::MOVE_RIGHT, deltaTime);
	}

	this->physicsWorld->Simulate(deltaTime);
}

void SuperGame::drawScene()
{
	this->window->Clear(0.76f, 0.84f, 0.91f, 1.0f);

	this->shader->Bind();

	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		this->shader->Update(*this->objects[i]->GetTransform(), this->playerCamera->GetCamera());
		this->objects[i]->Render();
	}

	this->shader->Unbind();

	this->window->SwapBuffers();
}