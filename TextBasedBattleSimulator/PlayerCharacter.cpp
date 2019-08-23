#include"PlayerCharacter.h"
#include "GameManager.h"
#include "BattleManager.h"

PlayerCharacter::PlayerCharacter()
{
	name = "playerName";
}

PlayerCharacter::PlayerCharacter(string _name)
{
	maxHP = 20;
	curHP = 20;
	atk = 5;
	name = _name;
}

PlayerCharacter::~PlayerCharacter()
{
	cout << name << " destroyed!" << endl;
}

void PlayerCharacter::Attack(IDamageable* target)
{
	Character::Attack(target);
	BattleManager::EndTurn(true);
}

void PlayerCharacter::ObtainGold(int amount)
{
	gold += amount;
	cout << name << " obtained " << amount << " gold!" << endl;
}

void PlayerCharacter::OnDeath()
{
	IDamageable::OnDeath();
	GameManager::EndGame();
}

