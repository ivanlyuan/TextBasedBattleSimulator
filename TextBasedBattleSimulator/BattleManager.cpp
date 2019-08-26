#include "BattleManager.h"
#include "GameManager.h" 
#include "MenuManager.h"
#include <algorithm>

bool BattleManager::isPlayerTurn = true;
vector<EnemyCharacter*> BattleManager::enemies;
PlayerCharacter* BattleManager::player;

BattleManager::BattleManager()
{
	
}

BattleManager::~BattleManager()
{
}

void BattleManager::StartWave(int level, PlayerCharacter* _player)
{
	//set up characters
	EnemyCharacter* enemy1 = new EnemyCharacter("enemy1");
	EnemyCharacter* enemy2 = new EnemyCharacter("enemy2");
	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	player = _player;
	
	//print enemy data
	//

	//start battle
	GameManager::SetGameState(GameManager::Battle);
	MenuManager::BattleActionMenu();

}

void BattleManager::TryEndWave()
{
	if (enemies.size() == 0)
	{
		cout << "==========Wave ended==========" << endl;
		GameManager::SetGameState(GameManager::Shop);
		MenuManager::ShopMenu();
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


	if (isPlayer)
	{
		MenuManager::BattleActionMenu();
	}
	else
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
		StartTurn(isPlayerTurn);
	}
	else
	{
		cout << "Error : It's not" << (isPlayerTurn ? "Player's" : "Enemies'") << " turn to end" << endl;
	}
}

