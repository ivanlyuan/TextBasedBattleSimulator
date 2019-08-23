#include "GameManager.h"


GameState GameManager::gameState;


GameManager::GameManager()
{

}

GameManager::~GameManager()
{
}

void GameManager::StartGame()
{
	cout << "GameManager.StartGame()" << endl;
}

void GameManager::EndGame()
{
	cout << "GameManager.EndGame()" << endl;
}

void GameManager::SetGameState(GameState gs)
{
	gameState = gs;
	cout << "Set GameState to " << gs << endl;
}
