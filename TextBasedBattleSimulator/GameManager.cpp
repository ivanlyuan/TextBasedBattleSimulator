#include "GameManager.h"
#include "MenuManager.h"
#include "BattleManager.h"


GameManager::GameState GameManager::gameState;


GameManager::GameManager()
{

}

GameManager::~GameManager()
{
}

void GameManager::StartGame()
{
	cout << "GameManager.StartGame()" << endl;
	PlayerCharacter* p = new PlayerCharacter();
	BattleManager::StartWave(0, p);
}

void GameManager::EndGame()
{
	cout << "GameManager.EndGame()" << endl;
	MenuManager::MainMenu();
}

void GameManager::SetGameState(GameState gs)
{
	gameState = gs;
	cout << "Set GameState to " << gs << endl;
}
