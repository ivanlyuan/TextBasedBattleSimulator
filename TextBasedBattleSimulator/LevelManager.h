#pragma once
#include "BattleManager.h"

class LevelManager
{
public:
	static void SetUpLevel(int level);
	static bool Init();
private:
	LevelManager();
	static vector<vector<EnemyCharacter*> > Enemies;
	
};
