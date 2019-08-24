#pragma once

#include "PlayerCharacter.h"



class GameManager
{
public:
	enum GameState
	{
		MainMenu,
		Battle,
		Shop

	};
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
