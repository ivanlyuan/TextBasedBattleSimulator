#include "LevelManager.h"
#include <fstream>

vector<vector<EnemyCharacter*> > LevelManager::Enemies;

void LevelManager::SetUpLevel(int level)
{
	if (level >= Enemies.size())
	{
		cout << "Error: LevelManager::SetUpLevel() failed" << endl;
		return;
	}
	BattleManager::SetUpLevel(Enemies[level]);


}

bool LevelManager::Init()
{
	Enemies.clear();
	std::ifstream fin;
	string s;
	fin.open("levels.txt");
	if (!fin)
	{
		std::cerr << "Error: failed to open levels.txt" << endl;
		return false;
	}

	while (std::getline(fin, s))
	{
		vector<EnemyCharacter*> LevelEnemies;

		for (int i = 0; i < s.size(); i++)
		{
			EnemyCharacter* e = new EnemyCharacter(EnemyCharacter::EnemyType(int(s[i] - '0')));
			LevelEnemies.push_back(e);
		}
		Enemies.push_back(LevelEnemies);
	}

	return true;

}


