#pragma once
#include <vector>
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"

using std::vector;

class BattleManager
{
public:

	static void StartWave(int level, PlayerCharacter* _player);
	static void TryEndWave();
	static void EnemiesTurn();
	static vector<EnemyCharacter*> GetEnemies() { return enemies; };
	static PlayerCharacter* GetPlayer() { return player; };
	static void RemoveEnemy(EnemyCharacter* enemy);
	static void EndTurn(bool isPlayer);
private:
	BattleManager();
	~BattleManager();
	static bool isPlayerTurn;
	static PlayerCharacter* player;
	static vector<EnemyCharacter*> enemies;

};


