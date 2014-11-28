#pragma once

#include <Engine\core\Window.h>
#include <Engine\core\VertexModel.h>
#include <Engine\core\Utils.h>
#include <Engine\rendering\DynamicMesh.h>
#include <Engine\rendering\Shader.h>
#include <Engine\rendering\Texture.h>
#include <Engine\rendering\Camera.h>
#include <Engine\rendering\Material.h>
#include <Engine\entities\Object.h>
#include <Engine\entities\DynamicObject.h>
#include <Engine\physics\PhysicsWorld.h>
#include <Engine\physics\SphericalCollider.h>
#include <Engine\physics\MeshCollider.h>
#include <Engine\core\IOManager.h>
#include "Constants.h"
#include "Player.h"
#include "InputManager.h"
#include "PlayerCamera.h"
#include "Player.h"

enum GameState
{
	INIT,
	RUNNING,
	EXIT
};

class SuperGame
{
public:
	SuperGame();
	~SuperGame();

	void Run();

private:
	Engine::VertexModel getTestModel();

	void loop();
	void processInput();
	void processLogic();
	void drawScene();
	void outputFPS();
	float time;
	GameState gameState;

	Engine::Window* window;
	Engine::Shader* shader;

	Engine::PhysicsWorld* physicsWorld;
	std::vector<Engine::Object*> objects;

	Player* player = &Player::GetInstance();
	PlayerCamera* playerCamera = &PlayerCamera::GetInstance();
	InputManager* inputManager = &InputManager::GetInstance();

	float currentFPS;

	float angle = 0.0;

	Engine::DynamicMesh* boxMesh;
	Engine::Material* bricksMaterial;
};