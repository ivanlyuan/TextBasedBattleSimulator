#include "BattleManager.h"
#include "GameManager.h" 
#include "MenuManager.h"
#include "LevelManager.h"
#include <algorithm>

bool BattleManager::isPlayerTurn = true;
vector<EnemyCharacter*> BattleManager::enemies;
PlayerCharacter* BattleManager::player;

void BattleManager::StartBattle(PlayerCharacter* _player)
{
	//check curLevel and set up accordingly
	LevelManager::SetUpLevel(GameManager::GetCurLevel());

	//set up characters

	player = _player;
	
	//print enemy data
	cout << "==========Battle Start==========" << endl;
	cout << "Enemies: ";
	for (size_t i = 0; i < enemies.size(); i++)
	{
		cout << enemies[i]->GetName() << endl;
	}

	//start battle
	while (GameManager::GetGameState() == GameManager::Battle)
	{
		StartTurn(isPlayerTurn);
	}
}

void BattleManager::TryEndBattle()
{
	if (enemies.size() == 0)
	{
		if (GameManager::GetCurLevel() == LevelManager::GetEnemies().size()-1)//is last level
		{
			GameManager::EndGame();
			return;
		}

		cout << "==========End of Battle==========" << endl;
		GameManager::SetGameState(GameManager::Shop);
	}
}

void BattleManager::StartTurn(bool isPlayer)
{
	if (GameManager::GetGameState() != GameManager::Battle)
	{
		return;
	}

	cout << endl;
	cout << "==========" << (isPlayerTurn ? "Player's" : "Enemies'") << " turn" << "==========" << endl;


	if (isPlayer)//player's turn
	{
		MenuManager::BattleActionMenu();
	}
	else//enemies' turn
	{
		for (unsigned int i = 0; i < enemies.size(); i++)
		{
			//enemies pick random actions
			//
			//
			enemies[i]->Attack(player);
		}
	}


	EndTurn(isPlayer);
}

void BattleManager::RemoveEnemy(EnemyCharacter* enemy)
{

	std::vector<EnemyCharacter*>::iterator position = std::find(enemies.begin(), enemies.end(), enemy);
	if (position != enemies.end())
	{
		enemies.erase(position);
	}
	else
	{
		cout << "Error: RemoveEnemy() failed" << endl;
	}

}

void BattleManager::EndTurn(bool isPlayer)
{
	if (GameManager::GetGameState() != GameManager::Battle)
	{
		return;
	}


	if (isPlayerTurn == isPlayer)
	{
		isPlayerTurn = !isPlayerTurn;
	}
	else
	{
		cout << "Error : It's not" << (isPlayerTurn ? "Player's" : "Enemies'") << " turn to end" << endl;
	}
}

void BattleManager::SetUpLevel(vector<EnemyCharacter*> _enemies)
{
	enemies = _enemies;
}

