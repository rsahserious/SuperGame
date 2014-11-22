#include <iostream>
#include "SuperGame.h"

int main(int argc, char** argv)
{
	SuperGame* game = new SuperGame();
	game->Run();

	delete game;

	return 0;
}