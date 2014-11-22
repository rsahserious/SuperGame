#include "SuperGame.h"

SuperGame::SuperGame()
{
	this->window = new Engine::Window("Super Game", Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);

	this->physicsWorld = new Engine::PhysicsWorld();
	this->physicsWorld->SetGravityStrength(8.0f);

	Engine::MeshCollider* mcollider = new Engine::MeshCollider(*Engine::IOManager::ReadObjModel("models/terrain.obj"));
	Engine::Object* terrain = new Engine::Object("models/terrain.obj", "textures/grass.png", mcollider);
	//terrain->GetTransform()->SetScale(glm::vec3(1, 0, 1));

	this->objects.push_back(terrain);
	this->physicsWorld->AddObject(terrain);

	for (int i = 0; i < 3; i++)
	{
		//Engine::RectangularCollider* collider1 = new Engine::RectangularCollider(
		//	glm::vec3(1.33f, 1.09f, 1.246f), glm::vec3(-1.31f, -1.16f, -1.264f));
		Engine::SphericalCollider* collider = new Engine::SphericalCollider(glm::vec3(0, 0, 0), 1.0f);

		Engine::DynamicObject* object = new Engine::DynamicObject("models/sphere.obj", "textures/rocks.png", collider);
		object->GetTransform()->SetPos(glm::vec3(-10.0f + (float)i / 50.0f, 45.0f + (i * 3), 0.0f + ((float)i / 50.0f)));
		object->GetPhysicsData()->SetVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
		//object1->GetPhysicsData()->SetAngularVelocity(glm::vec3(0.3f, 0.1f, 0.0f));

		this->objects.push_back(object);
		this->physicsWorld->AddObject(object);
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
		const int ticks = SDL_GetTicks();

		this->processInput();
		this->processLogic();
		this->drawScene();

		this->currentFPS = Engine::Utils::GetFPS();

		// Output current FPS
		static int ticks_snapshot = ticks;
		if (ticks - ticks_snapshot >= Constants::FPS_OUTPUT_INTERVAL)
		{
			std::cout << "FPS: " << (int)this->currentFPS << std::endl;
			ticks_snapshot = ticks;
		}
		
		// Calculate this frame's time
		int frameTime = SDL_GetTicks() - ticks;

		// FPS limiter
		static float fpsTime = 1000.0f / Constants::FPS_LIMIT;
		if (fpsTime > frameTime)
		{
			SDL_Delay(fpsTime - frameTime);
		}
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

void SuperGame::processLogic()
{
	this->angle += 0.01;

	if (this->inputManager->IsKeyDown(SDLK_w))
	{
		this->player->ExecuteAction(PlayerAction::MOVE_FORWARD);
	}

	if (this->inputManager->IsKeyDown(SDLK_s))
	{
		this->player->ExecuteAction(PlayerAction::MOVE_BACKWARD);
	}

	if (this->inputManager->IsKeyDown(SDLK_a))
	{
		this->player->ExecuteAction(PlayerAction::MOVE_LEFT);
	}

	if (this->inputManager->IsKeyDown(SDLK_d))
	{
		this->player->ExecuteAction(PlayerAction::MOVE_RIGHT);
	}

	this->physicsWorld->Simulate();
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