#include "pch.h"
#include "Application.h"

int main() 
{
	Game game;

	game.Initialize();

	while (game.getR()) 
	{
		game.Running();

		// Close Window
		if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) 
			game.setR(false);
	}


	game.ShutDown();

	return 0;
}