#pragma once
#include "BattleManager.h"

class LevelManager
{
public:
	static void SetUpLevel(int level);
	static bool Init();
	static vector<vector<EnemyCharacter*> > GetEnemies() { return Enemies; };
private:
	LevelManager();
	static vector<vector<EnemyCharacter*> > Enemies;
	
};
