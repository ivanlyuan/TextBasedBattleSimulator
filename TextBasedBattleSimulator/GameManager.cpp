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
	//cout << "GameManager.StartGame()" << endl;
	curLevel = 0;
	if (!LevelManager::Init())
	{
		return;
	}
	PlayerCharacter* p = new PlayerCharacter();
	Shop::InitUpgrades();
	BattleManager::StartWave(p);
}

void GameManager::EndGame()
{
	//cout << "GameManager.EndGame()" << endl;
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


