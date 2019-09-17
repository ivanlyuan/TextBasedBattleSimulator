#pragma once
#include <vector>
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"

using std::vector;

class BattleManager
{
public:

	static void StartBattle(PlayerCharacter* _player);
	static void TryEndBattle();
	static void StartTurn(bool isPlayer);
	static vector<EnemyCharacter*> GetEnemies() { return enemies; };
	static PlayerCharacter* GetPlayer() { return player; };
	static void RemoveEnemy(EnemyCharacter* enemy);
	static void EndTurn(bool isPlayer);
	static void SetUpLevel(vector<EnemyCharacter*> _enemies);
private:
	BattleManager();
	~BattleManager();
	static bool isPlayerTurn;
	static PlayerCharacter* player;
	static vector<EnemyCharacter*> enemies;

};


