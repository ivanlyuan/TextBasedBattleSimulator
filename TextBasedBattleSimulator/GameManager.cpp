#include "GameManager.h"
#include "MenuManager.h"
#include "BattleManager.h"
#include "LevelManager.h"


GameManager::GameState GameManager::gameState;
unsigned int GameManager::curLevel;


void GameManager::NextLevel()
{
	curLevel++;
}

GameManager::GameManager()
{

}

void GameManager::StartGame()
{
	cout << "==========Game Start==========" << endl;
	curLevel = 0;
	if (!LevelManager::Init())
	{
		return;
	}
	PlayerCharacter* p = new PlayerCharacter();
	Shop::InitUpgrades();
	SetGameState(GameState::Battle);

	while (gameState != GameState::MainMenu)//game loop
	{
		if (gameState == GameState::Battle)
		{
			BattleManager::StartBattle(p);
		}
		
		if (gameState == GameState::Shop)
		{
			MenuManager::ShopMenu();
		}

	}

}

void GameManager::EndGame()
{
	cout << "=====Game Over=====" << endl;
	MenuManager::MainMenu();
}

void GameManager::SetGameState(GameState gs)
{
	gameState = gs;
	cout << "Set GameState to " << gs << endl;
	if (gs == GameState::Shop)
	{
		Shop::ShuffleUpgrades(3);
		BattleManager::GetPlayer()->FullRestore();
	}
}


