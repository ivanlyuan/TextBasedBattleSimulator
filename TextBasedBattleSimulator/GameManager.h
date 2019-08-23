#pragma once

#include "PlayerCharacter.h"


enum GameState
{
	MainMenu,
	Shop,
	Battle
};
class GameManager
{
public:


	static void StartGame();
	static void EndGame();
	static void SetGameState(GameState gs);
	static GameState GetGameState() { return gameState; };
private:
	GameManager();
	~GameManager();
	static GameState gameState;
	static PlayerCharacter player;
	

};
