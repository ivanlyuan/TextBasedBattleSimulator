#include "BattleManager.h"
#include "GameManager.h" 
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
	EnemyCharacter* enemy1 = new EnemyCharacter("enemy1");
	EnemyCharacter* enemy2 = new EnemyCharacter("enemy2");
	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	player = _player;


}

void BattleManager::TryEndWave()
{
	if (enemies.size() == 0)
	{
		cout << "==========Wave ended==========" << endl;
		GameManager::SetGameState(Shop);
	}
}

void BattleManager::EnemiesTurn()
{
	if (GameManager::GetGameState() != Battle)
	{
		return;
	}


	for (int i = 0; i < enemies.size(); i++)
	{
		//enemies pick random actions
		//
		//
		enemies[i]->Attack(player);
	}

	EndTurn(false);
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
	if (GameManager::GetGameState() != Battle)
	{
		return;
	}


	if (isPlayerTurn == isPlayer)
	{
		cout << "==========" << (isPlayerTurn ? "Player's" : "Enemies'") << " turn ended" << "==========" << endl;
		isPlayerTurn = !isPlayerTurn;

		if (!isPlayerTurn)
		{
			EnemiesTurn();
		}

	}
	else
	{
		cout << "Error : It's not" << (isPlayerTurn ? "Player's" : "Enemies'") << " turn to end" << endl;
	}
}

