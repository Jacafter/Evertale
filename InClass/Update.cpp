#include "pch.h"
#include "Update.h"
#include "Player.h"
#include "Building.h"
#include "Nature.h"
#include "Combat.h"


#define NATURE_AMOUNT   15
#define NPC_AMOUNT      12
#define BUILDING_AMOUNT 6

// Initialization
Avatar* playerAvatar = new Avatar();
Enemy enemySoldier[NPC_AMOUNT];
Folk folkFriend[NPC_AMOUNT];
Boss bossMain[NPC_AMOUNT];
Building worldBuildings[BUILDING_AMOUNT];
Water* natureWater = new Water();
Rock natureRock[NATURE_AMOUNT];
Combat combatEnemy;
Camera2D myCamera;

extern bool _playerActive;

Update::Update()
{

}

Update::~Update()
{

}

void Update::setCamera()
{
	myCamera.target = playerAvatar->getPosition();
	myCamera.offset = Vector2{ 600 , 400 };
	myCamera.rotation = 0.0f;
	myCamera.zoom = 3.0f;
}

void Update::startCamera()
{
	BeginMode2D(myCamera);
}

void Update::updateCamera()
{
	// Camera Movement
	// - General
	myCamera.target = playerAvatar->getPosition();
	// - Overall Limit
	if (playerAvatar->getPosition().x <= 200)
	{
		myCamera.target = { 200 , playerAvatar->getPosition().y};
	}
	if (playerAvatar->getPosition().x >= 1000)
	{
		myCamera.target = { 1000 , playerAvatar->getPosition().y };
	}
	if (playerAvatar->getPosition().y <= 140)
	{
		myCamera.target = { playerAvatar->getPosition().x , 140 };
	}
	if (playerAvatar->getPosition().y >= 660)
	{
		myCamera.target = { playerAvatar->getPosition().x , 660 };
	}

	// - Corner Limits Fix
	if (playerAvatar->getPosition().x <= 200
		&& playerAvatar->getPosition().y <= 140)
	{
		myCamera.target = { 200 , 140 };
	} // Top-left
	if (playerAvatar->getPosition().x >= 1000
		&& playerAvatar->getPosition().y <= 140)
	{
		myCamera.target = { 1000 , 140 };
	} // Top-right
	if (playerAvatar->getPosition().x <= 200
		&& playerAvatar->getPosition().y >= 660)
	{
		myCamera.target = { 200 , 660 };
	} // Bottom-left
	if (playerAvatar->getPosition().x >= 1000
		&& playerAvatar->getPosition().y >= 660)
	{
		myCamera.target = { 1000 , 660 };
	} // Bottom-right
}

void Update::playerDraw()
{
	//Mountains	
	Vector2 mountPos01 = { 250 , 350 };// Top-left
	natureRock[1].setPosition(mountPos01);
	Vector2 mountSize01 = { 170 , 200 };
	natureRock[1].setSize(mountSize01);
	Rectangle mountRec01 = { natureRock[1].getPosition().x, natureRock[1].getPosition().y, natureRock[1].getSize().x, natureRock[1].getSize().y };
	natureRock[1].setRectangle(mountRec01);

	DrawTexturePro(natureRock->getTexture(), natureRock->getDrawSize(), natureRock[1].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });

	Vector2 mountPos02 = { 650 , 630 };// Bottom-center
	natureRock[2].setPosition(mountPos02);
	Vector2 mountSize02 = { 120 , 150 };
	natureRock[2].setSize(mountSize02);
	Rectangle mountRec02 = { natureRock[2].getPosition().x, natureRock[2].getPosition().y, natureRock[2].getSize().x, natureRock[2].getSize().y };
	natureRock[2].setRectangle(mountRec02);

	DrawTexturePro(natureRock->getTexture(), natureRock->getDrawSize(), natureRock[2].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });

	Vector2 mountPos03 = { 90 , 0 };// Top-offscreen
	natureRock[3].setPosition(mountPos03);
	Vector2 mountSize03 = { 90 , 100 };
	natureRock[3].setSize(mountSize03);
	Rectangle mountRec03 = { natureRock[3].getPosition().x, natureRock[3].getPosition().y, natureRock[3].getSize().x, natureRock[3].getSize().y };
	natureRock[3].setRectangle(mountRec03);

	DrawTexturePro(natureRock->getTexture(), natureRock->getDrawSize(), natureRock[3].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });

	Vector2 mountPos04 = { 650 , 150 };// Center
	natureRock[4].setPosition(mountPos04);
	Vector2 mountSize04 = { 150 , 170 };
	natureRock[4].setSize(mountSize04);
	Rectangle mountRec04 = { natureRock[4].getPosition().x, natureRock[4].getPosition().y, natureRock[4].getSize().x, natureRock[4].getSize().y };
	natureRock[4].setRectangle(mountRec04);

	DrawTexturePro(natureRock->getTexture(), natureRock->getDrawSize(), natureRock[4].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });

	// Buildings 
	Vector2 buildPos01 = { 1070 , 70 };// Top-right
	worldBuildings[1].setPosition(buildPos01);
	Vector2 buildSize01 = { 50 , 50 };
	worldBuildings[1].setSize(buildSize01);
	Rectangle buildRec01 = { worldBuildings[1].getPosition().x, worldBuildings[1].getPosition().y, worldBuildings[1].getSize().x, worldBuildings[1].getSize().y };
	worldBuildings[1].setRectangle(buildRec01);

	DrawTexturePro(worldBuildings->getTexture(), worldBuildings->getDrawSize(), worldBuildings[1].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });


	Vector2 buildPos02 = { 50 , 370 };// Center
	worldBuildings[2].setPosition(buildPos02);
	Vector2 buildSize02 = { 50 , 50 };
	worldBuildings[2].setSize(buildSize02);
	Rectangle buildRec02 = { worldBuildings[2].getPosition().x, worldBuildings[2].getPosition().y, worldBuildings[2].getSize().x, worldBuildings[2].getSize().y };
	worldBuildings[2].setRectangle(buildRec02);

	DrawTexturePro(worldBuildings->getTexture(), worldBuildings->getDrawSize(), worldBuildings[2].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });

	Vector2 buildPos03 = { 620 , 530 };// Center-left
	worldBuildings[3].setPosition(buildPos03);
	Vector2 buildSize03 = { 50 , 50 };
	worldBuildings[3].setSize(buildSize03);
	Rectangle buildRec03 = { worldBuildings[3].getPosition().x, worldBuildings[3].getPosition().y, worldBuildings[3].getSize().x, worldBuildings[3].getSize().y };
	worldBuildings[3].setRectangle(buildRec03);

	DrawTexturePro(worldBuildings->getTexture(), worldBuildings->getDrawSize(), worldBuildings[3].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });


	// Random Position
	srand((unsigned)time(NULL));
	int rangeX = 1000 - 200 + 1;
	int rangeY = 600 - 100 + 1;
	
	// - Enemy
	// Enemy 1 ---------------------------------------------- 
	int enemyPosX01 = rand() % rangeX + 200;
	int enemyPosY01 = rand() % rangeY + 100;
	static Vector2 enemyPos01 = { enemyPosX01 , enemyPosY01 };
	enemySoldier[1].setPosition(enemyPos01);
	Rectangle enemyRec01 = { enemySoldier[1].getPosition().x, enemySoldier[1].getPosition().y, enemySoldier[1].getSize().x, enemySoldier[1].getSize().y };
	enemySoldier[1].setRectangle(enemyRec01);
	
	for (int i = 0; i < NATURE_AMOUNT; i++) 	// Collision Correction
	{

		if ((CheckCollisionRecs(enemySoldier[1].getRectangle(), natureRock[i].getRectangle())))
		{
			int enemyPosX01 = rand() % rangeX + 200;
			int enemyPosY01 = rand() % rangeY + 100;
			static Vector2 enemyPos01 = { enemyPosX01 , enemyPosY01 };
			enemySoldier[1].setPosition(enemyPos01);
		}
	}

	if (enemySoldier[1].getStatus())
	{
		DrawTexturePro(enemySoldier->getTexture(), enemySoldier->getDrawSize(), enemySoldier[1].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });
	}

	// Enemy 2-----------------------------------------------
	int enemyPosX02 = rand() % rangeX + 200;
	int enemyPosY02 = rand() % rangeY + 100;
	static Vector2 enemyPos02 = { enemyPosX02 , enemyPosY02 };
	enemySoldier[2].setPosition(enemyPos02);
	Rectangle enemyRec02 = { enemySoldier[2].getPosition().x, enemySoldier[2].getPosition().y, enemySoldier[2].getSize().x, enemySoldier[2].getSize().y };
	enemySoldier[2].setRectangle(enemyRec02);
	
	for (int i = 0; i < NATURE_AMOUNT; i++) 	// Collision Correction
	{
		if ((CheckCollisionRecs(enemySoldier[2].getRectangle(), natureRock[i].getRectangle())))
		{
			int enemyPosX02 = rand() % rangeX + 200;
			int enemyPosY02 = rand() % rangeY + 100;
			static Vector2 enemyPos02 = { enemyPosX02 , enemyPosY02 };
			enemySoldier[2].setPosition(enemyPos02);
		}
	}
	
	if (enemySoldier[2].getStatus())
	{
		DrawTexturePro(enemySoldier->getTexture(), enemySoldier->getDrawSize(), enemySoldier[2].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });
	}

	// Enemy 3 ---------------------------------------------- 
	int enemyPosX03 = rand() % rangeX + 200;
	int enemyPosY03 = rand() % rangeY + 100;
	static Vector2 enemyPos03 = { enemyPosX03 , enemyPosY03 };
	enemySoldier[3].setPosition(enemyPos03);
	Rectangle enemyRec03 = { enemySoldier[3].getPosition().x, enemySoldier[3].getPosition().y, enemySoldier[3].getSize().x, enemySoldier[3].getSize().y };
	enemySoldier[3].setRectangle(enemyRec03);
	
	for (int i = 0; i < NATURE_AMOUNT; i++) 	// Collision Correction
	{
		if ((CheckCollisionRecs(enemySoldier[3].getRectangle(), natureRock[i].getRectangle())))
		{
			int enemyPosX03 = rand() % rangeX + 200;
			int enemyPosY03 = rand() % rangeY + 100;
			static Vector2 enemyPos03 = { enemyPosX03 , enemyPosY03 };
			enemySoldier[3].setPosition(enemyPos03);
		}
	}

	if (enemySoldier[3].getStatus())
	{
		DrawTexturePro(enemySoldier->getTexture(), enemySoldier->getDrawSize(), enemySoldier[3].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });
	}

	// Enemy 4 ---------------------------------------------- 
	int enemyPosX04 = rand() % rangeX + 200;
	int enemyPosY04 = rand() % rangeY + 100;
	static Vector2 enemyPos04 = { enemyPosX04 , enemyPosY04 };
	enemySoldier[4].setPosition(enemyPos04);
	Rectangle enemyRec04 = { enemySoldier[4].getPosition().x, enemySoldier[4].getPosition().y, enemySoldier[4].getSize().x, enemySoldier[4].getSize().y };
	enemySoldier[4].setRectangle(enemyRec04);
	
	for (int i = 0; i < NATURE_AMOUNT; i++) 	// Collision Correction
	{
		if ((CheckCollisionRecs(enemySoldier[4].getRectangle(), natureRock[i].getRectangle())))
		{
			int enemyPosX04 = rand() % rangeX + 200;
			int enemyPosY04 = rand() % rangeY + 100;
			static Vector2 enemyPos04 = { enemyPosX04 , enemyPosY04 };
			enemySoldier[4].setPosition(enemyPos04);
		}
	}

	if (enemySoldier[4].getStatus())
	{
		DrawTexturePro(enemySoldier->getTexture(), enemySoldier->getDrawSize(), enemySoldier[4].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });
	}

	// Enemy 5 ---------------------------------------------- 
	int enemyPosX05 = rand() % rangeX + 200; 
	int enemyPosY05 = rand() % rangeY + 100;
	static Vector2 enemyPos05 = { enemyPosX05 , enemyPosY05 };
	enemySoldier[5].setPosition(enemyPos05);
	Rectangle enemyRec05 = { enemySoldier[5].getPosition().x, enemySoldier[5].getPosition().y, enemySoldier[5].getSize().x, enemySoldier[5].getSize().y };
	enemySoldier[5].setRectangle(enemyRec05);

	for (int i = 0; i < NATURE_AMOUNT; i++) 	// Collision Correction
	{
		if ((CheckCollisionRecs(enemySoldier[5].getRectangle(), natureRock[i].getRectangle())))
		{
			int enemyPosX05 = rand() % rangeX + 200;
			int enemyPosY05 = rand() % rangeY + 100;
			static Vector2 enemyPos05 = { enemyPosX05 , enemyPosY05 };
			enemySoldier[5].setPosition(enemyPos05);
		}
	}

	if (enemySoldier[5].getStatus())
	{
		DrawTexturePro(enemySoldier->getTexture(), enemySoldier->getDrawSize(), enemySoldier[5].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });
	}

	// - Folks
    // Folk 1 ---------------------------------------------- 
	int folkPosX01 = rand() % rangeX + 200;
	int folkPosY01 = rand() % rangeY + 100;
	static Vector2 folkPos01 = { folkPosX01 , folkPosY01 };
	folkFriend[1].setPosition(folkPos01);
	Rectangle folkRec01 = { folkFriend[1].getPosition().x, folkFriend[1].getPosition().y, folkFriend[1].getSize().x, folkFriend[1].getSize().y };
	folkFriend[1].setRectangle(folkRec01);

	for (int i = 0; i < NATURE_AMOUNT; i++) 	// Collision Correction Nature
	{
		if ((CheckCollisionRecs(folkFriend[1].getRectangle(), natureRock[i].getRectangle())))
		{
			int folkPosX01 = rand() % rangeX + 200;
			int folkPosY01 = rand() % rangeY + 100;
			static Vector2 folkPos01 = { folkPosX01 , folkPosY01 };
			folkFriend[1].setPosition(folkPos01);
		}
	}
	for (int i = 0; i < NPC_AMOUNT; i++) // Collision Correction NPC
	{
		if ((CheckCollisionRecs(folkFriend[1].getRectangle(), enemySoldier[i].getRectangle())))
		{
			int folkPosX01 = rand() % rangeX + 200;
			int folkPosY01 = rand() % rangeY + 100;
			static Vector2 folkPos01 = { folkPosX01 , folkPosY01 };
			folkFriend[1].setPosition(folkPos01);
		}

	}

	DrawTexturePro(folkFriend->getTexture(), folkFriend->getDrawSize(), folkFriend[1].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });

	// Folk 2 ---------------------------------------------- 
	int folkPosX02 = rand() % rangeX + 200;
	int folkPosY02 = rand() % rangeY + 100;
	static Vector2 folkPos02 = { folkPosX02 , folkPosY02 };
	folkFriend[2].setPosition(folkPos02);
	Rectangle folkRec02 = { folkFriend[2].getPosition().x, folkFriend[2].getPosition().y, folkFriend[2].getSize().x, folkFriend[2].getSize().y };
	folkFriend[2].setRectangle(folkRec02);
	
	for (int i = 0; i < NATURE_AMOUNT; i++) 	// Collision Correction
	{
		if ((CheckCollisionRecs(folkFriend[2].getRectangle(), natureRock[i].getRectangle())))
		{
			int folkPosX02 = rand() % rangeX + 200;
			int folkPosY02 = rand() % rangeY + 100;
			static Vector2 folkPos02 = { folkPosX02 , folkPosY02 };
			folkFriend[2].setPosition(folkPos02);
		}
	};
	for (int i = 0; i < NPC_AMOUNT; i++) // Collision Correction NPC
	{
		if ((CheckCollisionRecs(folkFriend[2].getRectangle(), enemySoldier[i].getRectangle())))
		{
			int folkPosX02 = rand() % rangeX + 200;
			int folkPosY02 = rand() % rangeY + 100;
			static Vector2 folkPos02 = { folkPosX02 , folkPosY02 };
			folkFriend[2].setPosition(folkPos02);
		}

	};
	
	DrawTexturePro(folkFriend->getTexture(), folkFriend->getDrawSize(), folkFriend[2].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });
	
	// Folk 3 ---------------------------------------------- 
	int folkPosX03 = rand() % rangeX + 200;
	int folkPosY03 = rand() % rangeY + 100;
	static Vector2 folkPos03 = { folkPosX03 , folkPosY03 };
	folkFriend[3].setPosition(folkPos03);
	Rectangle folkRec03 = { folkFriend[3].getPosition().x, folkFriend[3].getPosition().y, folkFriend[3].getSize().x, folkFriend[3].getSize().y };
	folkFriend[3].setRectangle(folkRec03);

	for (int i = 0; i < NATURE_AMOUNT; i++) // Collision Correction
	{
		if ((CheckCollisionRecs(folkFriend[3].getRectangle(), natureRock[i].getRectangle())))
		{
			int folkPosX03 = rand() % rangeX + 200;
			int folkPosY03 = rand() % rangeY + 100;
			static Vector2 folkPos03 = { folkPosX03 , folkPosY03 };
			folkFriend[3].setPosition(folkPos03);
		}
	}
	for (int i = 0; i < NPC_AMOUNT; i++) // Collision Correction NPC
	{
		if ((CheckCollisionRecs(folkFriend[3].getRectangle(), enemySoldier[i].getRectangle())))
		{
			int folkPosX03 = rand() % rangeX + 200;
			int folkPosY03 = rand() % rangeY + 100;
			static Vector2 folkPos03 = { folkPosX03 , folkPosY03 };
			folkFriend[3].setPosition(folkPos03);
		}

	};

	DrawTexturePro(folkFriend->getTexture(), folkFriend->getDrawSize(), folkFriend[3].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });

	// -Boss
	// Boss 1 ---------------------------------------------- 
	int bossPosX01 = rand() % rangeX + 200;
	int bossPosY01 = rand() % rangeY + 100;
	static Vector2 bossPos01 = { bossPosX01 , bossPosY01 };
	bossMain[1].setPosition(bossPos01);
	Rectangle bossRec01 = { bossMain[1].getPosition().x, bossMain[1].getPosition().y, bossMain[1].getSize().x, bossMain[1].getSize().y };
	bossMain[1].setRectangle(bossRec01);

	for (int i = 0; i < NATURE_AMOUNT; i++) // Collision Correction
	{
		if ((CheckCollisionRecs(bossMain[1].getRectangle(), natureRock[i].getRectangle())))
		{
			int bossPosX01 = rand() % rangeX + 200;
			int bossPosY01 = rand() % rangeY + 100;
			static Vector2 bossPos01 = { bossPosX01 , bossPosY01 };
			bossMain[1].setPosition(bossPos01);
		}
	}
	for (int i = 0; i < NPC_AMOUNT; i++) // Collision Correction
	{
		if ((CheckCollisionRecs(bossMain[1].getRectangle(), folkFriend[i].getRectangle())))
		{
			int bossPosX01 = rand() % rangeX + 200;
			int bossPosY01 = rand() % rangeY + 100;
			static Vector2 bossPos01 = { bossPosX01 , bossPosY01 };
			bossMain[1].setPosition(bossPos01);
		}
		if ((CheckCollisionRecs(bossMain[1].getRectangle(), enemySoldier[i].getRectangle())))
		{
			int bossPosX01 = rand() % rangeX + 200;
			int bossPosY01 = rand() % rangeY + 100;
			static Vector2 bossPos01 = { bossPosX01 , bossPosY01 };
			bossMain[1].setPosition(bossPos01);
		}

	}

	if (bossMain[1].getStatus())
	{
		DrawTexturePro(bossMain->getTexture(), bossMain->getDrawSize(), bossMain[1].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });
	}

	// Boss 2 ---------------------------------------------- 
	int bossPosX02 = rand() % rangeX + 200;
	int bossPosY02 = rand() % rangeY + 100;
	static Vector2 bossPos02 = { bossPosX02 , bossPosY02 };
	bossMain[2].setPosition(bossPos02);
	Rectangle bossRec02 = { bossMain[2].getPosition().x, bossMain[2].getPosition().y, bossMain[2].getSize().x, bossMain[2].getSize().y };
	bossMain[2].setRectangle(bossRec02);

	for (int i = 0; i < NATURE_AMOUNT; i++) // Collision Correction Nature
	{
		if ((CheckCollisionRecs(bossMain[2].getRectangle(), natureRock[i].getRectangle())))
		{
			int bossPosX02 = rand() % rangeX + 200;
			int bossPosY02 = rand() % rangeY + 100;
			static Vector2 bossPos02 = { bossPosX02 , bossPosY02 };
			bossMain[2].setPosition(bossPos02);
		}
	}
	for (int i = 0; i < NPC_AMOUNT; i++) // Collision Correction NPC
	{
		if ((CheckCollisionRecs(bossMain[2].getRectangle(), folkFriend[i].getRectangle())))
		{
			int bossPosX02 = rand() % rangeX + 200;
			int bossPosY02 = rand() % rangeY + 100;
			static Vector2 bossPos02 = { bossPosX02 , bossPosY02 };
			bossMain[2].setPosition(bossPos02);
		}
		if ((CheckCollisionRecs(bossMain[2].getRectangle(), enemySoldier[i].getRectangle())))
		{
			int bossPosX02 = rand() % rangeX + 200;
			int bossPosY02 = rand() % rangeY + 100;
			static Vector2 bossPos02 = { bossPosX02 , bossPosY02 };
			bossMain[2].setPosition(bossPos02);
		}

	}

	if (bossMain[2].getStatus())
	{
		DrawTexturePro(bossMain->getTexture(), bossMain->getDrawSize(), bossMain[2].getRectangle(), { 0, 0 }, 0, { 255, 255, 255, 255 });
	}

	// Avatar
	// - Barbarian
	DrawTextureRec(playerAvatar->getTexture(), playerAvatar->getRectangle(), { playerAvatar->getPosition().x, playerAvatar->getPosition().y }, { 255, 255, 255, 255 });

	// - Combat Text
	for (int i = 0; i < NPC_AMOUNT; i++) // Enemy
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), enemySoldier[i].getRectangle()))
			&& enemySoldier[i].getStatus())
		{
			// - Stats
			DrawText(TextFormat("HP = %d", playerAvatar->getLife()), playerAvatar->getPosition().x + 130, playerAvatar->getPosition().y - 70, 2, { 255, 255, 255,255 });
			DrawText(TextFormat("ATK = %d", playerAvatar->getAttack()), playerAvatar->getPosition().x + 130, playerAvatar->getPosition().y - 60, 2, { 255, 255, 255,255 });
			DrawText(TextFormat("GOLD = %d", playerAvatar->getGold()), playerAvatar->getPosition().x + 130, playerAvatar->getPosition().y - 50, 2, { 255, 255, 255,255 });

			combatEnemy.enemyText();
			// - Combat Reaction
			if (IsKeyDown(KEY_A))
			{
				combatEnemy.combatAttack();
			}

			if (IsKeyDown(KEY_S))
			{
				combatEnemy.combatRun();
			}
		}
	}

	for (int i = 0; i < NPC_AMOUNT; i++) // Boss
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), bossMain[i].getRectangle()))
			&& bossMain[i].getStatus())
		{
			// - Stats
			DrawText(TextFormat("HP = %d", playerAvatar->getLife()), playerAvatar->getPosition().x + 130, playerAvatar->getPosition().y - 70, 2, { 255, 255, 255,255 });
			DrawText(TextFormat("ATK = %d", playerAvatar->getAttack()), playerAvatar->getPosition().x + 130, playerAvatar->getPosition().y - 60, 2, { 255, 255, 255,255 });
			DrawText(TextFormat("GOLD = %d", playerAvatar->getGold()), playerAvatar->getPosition().x + 130, playerAvatar->getPosition().y - 50, 2, { 255, 255, 255,255 });

			combatEnemy.bossText();
			// - Combat Reaction
			if (IsKeyDown(KEY_A))
			{
				combatEnemy.combatAttack();
			}

			if (IsKeyDown(KEY_S))
			{
				combatEnemy.combatRun();
			}
		}
	}

	for (int i = 0; i < NPC_AMOUNT; i++) // Folk
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), folkFriend[i].getRectangle()))
			&& folkFriend[i].getStatus())
		{
			// - Stats
			DrawText(TextFormat("HP = %d", playerAvatar->getLife()), playerAvatar->getPosition().x + 130, playerAvatar->getPosition().y - 70, 2, { 255, 255, 255,255 });
			DrawText(TextFormat("ATK = %d", playerAvatar->getAttack()), playerAvatar->getPosition().x + 130, playerAvatar->getPosition().y - 60, 2, { 255, 255, 255,255 });
			DrawText(TextFormat("GOLD = %d", playerAvatar->getGold()), playerAvatar->getPosition().x + 130, playerAvatar->getPosition().y - 50, 2, { 255, 255, 255,255 });

			combatEnemy.folkText();
			// - Combat Reaction
			if (IsKeyDown(KEY_A))
			{
				combatEnemy.combatTrade();
			}

			if (IsKeyDown(KEY_S))
			{
				combatEnemy.combatWalkAway();
			}
		}
	}
}

void Update::playerTexture()
{
	// Mountain
	Texture2D mountain = LoadTexture("../assets/Cliff.png");
	natureRock->setTexture(mountain);

	// Buildings
	Texture2D building = LoadTexture("../assets/Keep.png");
	worldBuildings->setTexture(building);

	// Avatar
	Texture2D character = LoadTexture("../assets/Börg.png");
	playerAvatar->setTexture(character);

	// Enemy
	Texture2D enemy = LoadTexture("../assets/SpearmanRed.png");
	enemySoldier->setTexture(enemy);

	// Folk
	Texture2D folk = LoadTexture("../assets/FarmerCyan.png");
	folkFriend->setTexture(folk);

	// Boss
	Texture2D boss = LoadTexture("../assets/ArmouredRedDemon.png");
	bossMain->setTexture(boss);
}

void Update::playerMovement()
{
	if (IsKeyDown(KEY_RIGHT))
	{
		Vector2 newPosition;
		float newPointx;

		newPointx = playerAvatar->getPosition().x + 2.0f;
		newPosition = { newPointx , playerAvatar->getPosition().y };

		playerAvatar->setPosition(newPosition);
	}

	if (IsKeyDown(KEY_LEFT))
	{
		Vector2 newPosition;
		float newPointx;

		newPointx = playerAvatar->getPosition().x - 2.0f;
		newPosition = { newPointx , playerAvatar->getPosition().y };

		playerAvatar->setPosition(newPosition);
	}

	if (IsKeyDown(KEY_UP))
	{
		Vector2 newPosition;
		float newPointy;

		newPointy = playerAvatar->getPosition().y - 2.0f;
		newPosition = { playerAvatar->getPosition().x , newPointy };

		playerAvatar->setPosition(newPosition);
	}

	if (IsKeyDown(KEY_DOWN))
	{
		Vector2 newPosition;
		float newPointy;

		newPointy = playerAvatar->getPosition().y + 2.0f;
		newPosition = { playerAvatar->getPosition().x , newPointy };

		playerAvatar->setPosition(newPosition);
	}
}

void Update::playerLimit()
{
	// Limits
	// - X Limit
	if (playerAvatar->getPosition().x <= 1)
	{
		int limitX = 1;
		Vector2 newPosition = { limitX , playerAvatar->getPosition().y };
		playerAvatar->setPosition(newPosition);
	}

	if (playerAvatar->getPosition().x >= 1185)
	{
		int limitX = 1185;
		Vector2 newPosition = { limitX , playerAvatar->getPosition().y };
		playerAvatar->setPosition(newPosition);
	}

	// - Y Limit
	if (playerAvatar->getPosition().y <= 1)
	{
		int limitY = 1;
		Vector2 newPosition = { playerAvatar->getPosition().x , limitY };
		playerAvatar->setPosition(newPosition);
	}


	if (playerAvatar->getPosition().y >= 783)
	{
		int limitY = 783;
		Vector2 newPosition = { playerAvatar->getPosition().x , limitY };
		playerAvatar->setPosition(newPosition);
	}
}

void Update::playerCollision()
{
	// Collision Detection
	// - Water Collision
	if (CheckCollisionPointRec(playerAvatar->getPosition(), natureWater->getRectangle()))
	{
		int limitX = playerAvatar->getPosition().x - 1;
		int limitY = playerAvatar->getPosition().y - 1;
		Vector2 newPosition = { limitX , limitY };
		playerAvatar->setPosition(newPosition);
	};

	// - Rock Collision
	for (int i = 0; i < NATURE_AMOUNT; i++)
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), natureRock[i].getRectangle())) // Bottom
			&& playerAvatar->getPosition().y <= natureRock[i].getPosition().y + natureRock[i].getSize().y
			&& playerAvatar->getPosition().y >= natureRock[i].getPosition().y + natureRock[i].getSize().y - 1)
		{
			int limitY = natureRock[i].getPosition().y + natureRock[i].getSize().y + 1;

			Vector2 newPosition = { playerAvatar->getPosition().x , limitY };
			playerAvatar->setPosition(newPosition);
		}

		if ((CheckCollisionPointRec(playerAvatar->getPosition(), natureRock[i].getRectangle())) // Top
			&& playerAvatar->getPosition().y >= natureRock[i].getPosition().y
			&& playerAvatar->getPosition().y <= natureRock[i].getPosition().y + 2)
		{
			int limitY = natureRock[i].getPosition().y - 1;

			Vector2 newPosition = { playerAvatar->getPosition().x , limitY };
			playerAvatar->setPosition(newPosition);
		}

		if ((CheckCollisionPointRec(playerAvatar->getPosition(), natureRock[i].getRectangle())) // Right
			&& playerAvatar->getPosition().x >= natureRock[i].getPosition().x
			&& playerAvatar->getPosition().x <= natureRock[i].getPosition().x + 1)
		{
			int limitX = natureRock[i].getPosition().x - 1;

			Vector2 newPosition = { limitX , playerAvatar->getPosition().y };
			playerAvatar->setPosition(newPosition);
		}

		if ((CheckCollisionPointRec(playerAvatar->getPosition(), natureRock[i].getRectangle())) // Left
			&& playerAvatar->getPosition().x <= natureRock[i].getPosition().x + natureRock[i].getSize().x
			&& playerAvatar->getPosition().x >= natureRock[i].getPosition().x - 1)
		{
			int limitX = natureRock[i].getPosition().x + natureRock[i].getSize().x + 1;

			Vector2 newPosition = { limitX , playerAvatar->getPosition().y };
			playerAvatar->setPosition(newPosition);
		}
	}

	// - Building Collision
	for (int i = 0; i < NATURE_AMOUNT; i++)
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), worldBuildings[i].getRectangle())) // Bottom
			&& playerAvatar->getPosition().y <= worldBuildings[i].getPosition().y + worldBuildings[i].getSize().y
			&& playerAvatar->getPosition().y >= worldBuildings[i].getPosition().y + worldBuildings[i].getSize().y - 1)
		{
			int limitY = worldBuildings[i].getPosition().y + worldBuildings[i].getSize().y + 1;

			Vector2 newPosition = { playerAvatar->getPosition().x , limitY };
			playerAvatar->setPosition(newPosition);
		}

		if ((CheckCollisionPointRec(playerAvatar->getPosition(), worldBuildings[i].getRectangle())) // Top
			&& playerAvatar->getPosition().y >= worldBuildings[i].getPosition().y
			&& playerAvatar->getPosition().y <= worldBuildings[i].getPosition().y + 2)
		{
			int limitY = worldBuildings[i].getPosition().y - 1;

			Vector2 newPosition = { playerAvatar->getPosition().x , limitY };
			playerAvatar->setPosition(newPosition);
		}

		if ((CheckCollisionPointRec(playerAvatar->getPosition(), worldBuildings[i].getRectangle())) // Right
			&& playerAvatar->getPosition().x >= worldBuildings[i].getPosition().x
			&& playerAvatar->getPosition().x <= worldBuildings[i].getPosition().x + 1)
		{
			int limitX = worldBuildings[i].getPosition().x - 1;

			Vector2 newPosition = { limitX , playerAvatar->getPosition().y };
			playerAvatar->setPosition(newPosition);
		}

		if ((CheckCollisionPointRec(playerAvatar->getPosition(), worldBuildings[i].getRectangle())) // Left
			&& playerAvatar->getPosition().x <= worldBuildings[i].getPosition().x + worldBuildings[i].getSize().x
			&& playerAvatar->getPosition().x >= worldBuildings[i].getPosition().x - 1)
		{
			int limitX = worldBuildings[i].getPosition().x + worldBuildings[i].getSize().x + 1;

			Vector2 newPosition = { limitX , playerAvatar->getPosition().y };
			playerAvatar->setPosition(newPosition);
		}
	}

	// Enemy Collision
	// - Combat
	for (int i = 0; i < NPC_AMOUNT; i++)
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), enemySoldier[i].getRectangle())))
		{
			Vector2 freezeMov = { enemySoldier[i].getPosition().x, enemySoldier[i].getPosition().y + 10 };
			playerAvatar->setPosition(freezeMov);

			Vector2 combatPosition = { playerAvatar->getPosition().x - 160, playerAvatar->getPosition().y + 50};
			combatEnemy.setPosition(combatPosition);
		}			
	}

	// Folk Collision
	for (int i = 0; i < NPC_AMOUNT; i++)
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), folkFriend[i].getRectangle())))
		{
			Vector2 freezeMov = { folkFriend[i].getPosition().x,  folkFriend[i].getPosition().y + 10};
			playerAvatar->setPosition(freezeMov);

			Vector2 combatPosition = { playerAvatar->getPosition().x - 160, playerAvatar->getPosition().y + 50 };
			combatEnemy.setPosition(combatPosition);
		}
	}

	// - Boss Collision
	for (int i = 0; i < NPC_AMOUNT; i++)
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), bossMain[i].getRectangle())))
		{
			Vector2 freezeMov = { bossMain[i].getPosition().x, bossMain[i].getPosition().y + 15 };
			playerAvatar->setPosition(freezeMov);

			Vector2 combatPosition = { playerAvatar->getPosition().x - 160, playerAvatar->getPosition().y + 50 };
			combatEnemy.setPosition(combatPosition);
		}
	}

	// - Enemy Damage
	for (int i = 0; i < NPC_AMOUNT; i++)
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), enemySoldier[i].getRectangle())))
		{
			if (enemySoldier[i].getLife() < 0)
			{
				int earnGold = playerAvatar->getGold() + 10;
				playerAvatar->setGold(earnGold);

				enemySoldier[i].setStatus(false);
			}
			// Status Player con global
						// Status Player con global
			if (playerAvatar->getLife() < 0)
			{
				_playerActive = false;
			}

			if (IsKeyDown(KEY_A))
			{
				int playerDamage = playerAvatar->getLife() - enemySoldier->getAttack();
				playerAvatar->setLife(playerDamage);

				int enemyDamage = enemySoldier[i].getLife() - playerAvatar->getAttack();
				enemySoldier[i].setLife(enemyDamage);
			}

			if (IsKeyDown(KEY_S))
			{
				int playerDamage = playerAvatar->getLife() - enemySoldier->getAttack();
				playerAvatar->setLife(playerDamage);
			}
		}
	}

	// - Boss Damage
	for (int i = 0; i < NPC_AMOUNT; i++)
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), bossMain[i].getRectangle())))
		{
			if (bossMain[i].getLife() < 0)
			{
				bossMain[i].setStatus(false);
				int earnGold = playerAvatar->getGold() + 25;
				playerAvatar->setGold(earnGold);
			}
			// Status Player con global
						// Status Player con global
			if (playerAvatar->getLife() < 0)
			{
				_playerActive = false;
			}

			if (IsKeyDown(KEY_A))
			{
				int playerDamage = playerAvatar->getLife() - bossMain->getAttack();
				playerAvatar->setLife(playerDamage);

				int enemyDamage = bossMain[i].getLife() - playerAvatar->getAttack();
				bossMain[i].setLife(enemyDamage);
			}

			if (IsKeyDown(KEY_S))
			{
				int playerDamage = playerAvatar->getLife() - bossMain->getAttack();
				playerAvatar->setLife(playerDamage);
			}
		}
	}

	// - NPC Exchange
	for (int i = 0; i < NPC_AMOUNT; i++)
	{
		if ((CheckCollisionPointRec(playerAvatar->getPosition(), folkFriend[i].getRectangle())))
		{
			if (IsKeyDown(KEY_A))
			{
				int loseGold = playerAvatar->getGold() - 50;
				playerAvatar->setGold(loseGold);

				int upAttack = playerAvatar->getAttack() + 10;
				playerAvatar->setAttack(upAttack);
			}
		}
	}
}

bool Update::getPause() const
{
	return _pause;
}

void Update::setPause(bool pause)
{
	_pause = pause;
}

void Update::setSound()
{

}