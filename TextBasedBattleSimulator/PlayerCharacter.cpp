#include"PlayerCharacter.h"
#include "GameManager.h"
#include "BattleManager.h"

PlayerCharacter::PlayerCharacter()
{
	maxHP = 20;
	curHP = 20;
	atk = 5;
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

void PlayerCharacter::ApplyUpgrade(ShopUpgrade * su)
{
	cout << "Applied upgrade " << endl;

	switch (su->GetStatType())
	{
	case StatType::atk:
		Character::atk += su->GetAmount();
		break;
	case StatType::hp:
		Character::maxHP += su->GetAmount();
		Character::curHP += su->GetAmount();
		break;
	case StatType::mp:
		Character::maxMP += su->GetAmount();
		Character::curMP += su->GetAmount();
		break;
	case StatType::spellSlot:
		Character::spellSlots += su->GetAmount();
		break;
	default:
		cout << "Invalid stat type" << endl;
		break;
	}
}

void PlayerCharacter::OnDeath()
{
	IDamageable::OnDeath();
	delete this;
	GameManager::EndGame();
}

