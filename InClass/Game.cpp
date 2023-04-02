#include "pch.h"
#include "Game.h"
#include "Update.h"
#include "World.h"
#include "Combat.h"

// Initialize Screens
typedef enum gameScreen { gameTitle = 0, gameMenu, gameSettings, gameInstructions, gamePlay, gameOver } gameScreen;
gameScreen currentScreen = gameTitle;
int framesCounter = 0;

// Elements
Update myUpdate;
World myWorld;
Combat myCombat;

// Global Variable
bool _playerActive = true;

Game::Game()
{
	// Constructor
};

Game::~Game()
{
	// Deconstructor
};

bool Game::getR() const
{
	return m_Running;
};

void Game::setR(bool b)
{
	m_Running = b;
};

void Game::Initialize()
{
	InitAudioDevice();

	// Create a Window
	const int screenWidth = 1200;
	const int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "Everafter");
	
	Music Sound = LoadMusicStream("resources/Adventure-320bit.mp3");
	PlayMusicStream(Sound);

	if (IsMusicStreamPlaying(Music (Sound)))
	{
		std::cout <<"HELLLOOOO" << std::endl;
	}

	// Load images
	myWorld.worldTexture();
	myUpdate.playerTexture();

	// Set Camera
	myUpdate.setCamera();

	SetTargetFPS(60);
	// Set our game to run at 60 frames-per-second
};

void Game::Running()
{
	// Game Screens
	switch (currentScreen)
	{
		// Title
		case gameTitle:
		{
			framesCounter++;
			if (framesCounter > 180)
			{
				currentScreen = gameMenu;
			}
		} break;

		// Menu
		case gameMenu:
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				currentScreen = gamePlay;
			}
			if (IsKeyPressed(KEY_SPACE))
			{
				currentScreen = gameInstructions;
			}
			if (IsKeyPressed(KEY_TAB))
			{
				currentScreen = gameSettings;
			}
		} break;

		// Instructions
		case gameInstructions:
		{
			if (IsKeyPressed(KEY_SPACE))
			{
				currentScreen = gameMenu;
			}
		} break;

		// Settings
		case gameSettings:
		{
			if (IsKeyPressed(KEY_SPACE))
			{
				currentScreen = gameMenu;
			}
		} break;

		// Main Game
		case gamePlay:
		{
			// Set Music
			InputSys();
			UpdateSys();

			if (!_playerActive) // Add bool _active Player
			{
				currentScreen = gameOver;
			}
		} break;

		// Game Over
		case gameOver:
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				currentScreen = gameTitle;
				framesCounter = 0;
			}
		} break;
		default: break;
	}
	DisplaySys();
};

void Game::ShutDown()
{
	// De-Initialization
	CloseWindow();
};


void Game::InputSys()
{
	// Player Movement
	myUpdate.playerMovement();
};

void Game::UpdateSys()
{
	// Camera 
	myUpdate.updateCamera();

	// Player
	myUpdate.playerLimit();
	myUpdate.playerCollision();
};

void Game::DisplaySys()
{
	// Draw
	BeginDrawing();

	// Screens
	switch (currentScreen)
	{
		// Title
		case gameTitle:
		{
			DrawRectangle(0, 0, 1200, 800, BLACK);
			DrawText("Evertale", 375, 320, 100, LIGHTGRAY);
		} break;

		// Menu
		case gameMenu:
		{
			DrawRectangle(0, 0, 1200, 800, DARKGRAY);
			DrawText("Main Menu", 470, 200, 50, WHITE);
			DrawText("Press ENTER to start", 460, 350, 25, SKYBLUE);
			DrawText("Press SPACE to read the instructions", 360, 400, 25, SKYBLUE);
			DrawText("Press TAB to see settings", 430, 450, 25, SKYBLUE);

		} break;

		// Instructions
		case gameInstructions:
		{
			DrawRectangle(0, 0, 1200, 800, DARKGRAY);
			DrawText("Instructions", 440, 200, 50, WHITE);
			DrawText("Use the navigatio keys to move around", 360, 350, 25, SKYBLUE);
			DrawText("Use A or S to select an option", 400, 400, 25, SKYBLUE);
			DrawText("Press SPACE to return to Main Menu", 360, 500, 25, SKYBLUE);
		} break;

		// Instructions
		case gameSettings:
		{
			DrawRectangle(0, 0, 1200, 800, DARKGRAY);
			DrawText("Settings", 490, 200, 50, WHITE);
			DrawText("Press P to pause/start music", 420, 350, 25, SKYBLUE);
			DrawText("Press SPACE to return to Main Menu", 370, 400, 25, SKYBLUE);
		} break;

		// Main Game
		case gamePlay:
		{
			// Spatial UI
			myUpdate.startCamera();

			// Elements
			myWorld.worldDraw();
			myUpdate.playerDraw();
		} break;

		// Game Over
		case gameOver:
		{
			DrawRectangle(0, 0, 1200, 800, BLACK);
			DrawText("YOU DIE", 500, 350, 50, RED);
		} break;
		default: break;
	}
	EndDrawing();
};
