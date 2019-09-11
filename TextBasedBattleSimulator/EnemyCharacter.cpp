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

EnemyCharacter::EnemyCharacter(EnemyType et)
{
	isIdentified = true;
	switch (et)
	{
	case EnemyCharacter::solider:
		name = "Solider";
		maxHP = 15;
		curHP = 15;
		maxMP = 0;
		curMP = 0;
		atk = 4;
		gold = 10;
		break;
	case EnemyCharacter::mage:
		name = "Mage";
		maxHP = 12;
		curHP = 12;
		maxMP = 0;
		curMP = 0;
		atk = 6;
		gold = 12;
		break;
	case EnemyCharacter::eliteSolider:
		name = "Elite Solider";
		maxHP = 24;
		curHP = 24;
		maxMP = 0;
		curMP = 0;
		atk = 6;
		gold = 20;
		break;
	case EnemyCharacter::archmage:
		name = "Archmage";
		maxHP = 20;
		curHP = 20;
		maxMP = 0;
		curMP = 0;
		atk = 8;
		gold = 24;
		break;
	case EnemyCharacter::champion:
		name = "Champion";
		maxHP = 120;
		curHP = 120;
		maxMP = 0;
		curMP = 0;
		atk = 8;
		gold = 120;
		break;
	default:
		break;
	}
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
