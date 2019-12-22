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
	cout << "Enemies:" << endl;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		cout << enemies[i]->GetName() << endl;
	}

	//start battle
	isPlayerTurn = true;
	while (GameManager::GetGameState() == GameManager::Battle)
	{
		StartTurn(isPlayerTurn);
		EndTurn(isPlayerTurn);
	}
}

void BattleManager::TryEndBattle()
{
	if (enemies.size() == 0)
	{
		if (GameManager::GetCurLevel() == LevelManager::GetEnemies().size()-1)//is last level
		{
			cout << "Congratulations!  You beat the game!" << endl;
			GameManager::SetGameState(GameManager::MainMenu);
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
		player->SetHasAttacked(false);
		while (!player->GetHasAttacked())
		{
			MenuManager::BattleActionMenu();
		}
	}
	else//enemies' turn
	{
		for (unsigned int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->SetHasAttacked(false);
		}

		for (unsigned int i = 0; i < enemies.size(); i++)
		{
			//enemies pick random actions
			//
			//
			if (!player->GetIsAlive())
			{
				break;
			}
			enemies[i]->Attack(player);
		}
	}


}

void BattleManager::RemoveEnemy(EnemyCharacter* enemy)
{

	std::vector<EnemyCharacter*>::iterator position = std::find(enemies.begin(), enemies.end(), enemy);
	if (position != enemies.end())
	{
		delete enemy;
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

