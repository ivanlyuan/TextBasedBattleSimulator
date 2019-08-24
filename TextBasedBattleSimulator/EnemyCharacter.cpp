#include"EnemyCharacter.h"
#include"BattleManager.h"

EnemyCharacter::EnemyCharacter()
{
	name = "EnemyName";
	gold = 10;
	isIdentified = true;
}

EnemyCharacter::EnemyCharacter(string _name)
{
	name = _name;
	gold = 10;
	isIdentified = true;
}

EnemyCharacter::~EnemyCharacter()
{
	BattleManager::RemoveEnemy(this);
	BattleManager::GetPlayer()->ObtainGold(gold);
}

void EnemyCharacter::OnDeath()
{
	IDamageable::OnDeath();
	delete this;//calls destructor
	BattleManager::TryEndWave();
}
