#include"PlayerCharacter.h"
#include "GameManager.h"
#include "BattleManager.h"

PlayerCharacter::PlayerCharacter()
{
	maxHP = 25;
	curHP = 25;
	maxMP = 25;
	curMP = 25;
	atk = 5;
	name = "Player";
}

PlayerCharacter::PlayerCharacter(string _name)
{
	PlayerCharacter();
	name = _name;
}

PlayerCharacter::~PlayerCharacter()
{
	cout << name << " destroyed!" << endl;
}

bool PlayerCharacter::Attack(IDamageable* target)
{
	return Character::Attack(target);
}

void PlayerCharacter::ObtainGold(int amount)
{
	gold += amount;
	cout << name << " obtained " << amount << " gold!" << endl;
}

void PlayerCharacter::ApplyUpgrade(ShopUpgrade * su)
{

	unsigned int amount = su->GetAmount();
	switch (su->GetStatType())
	{
	case StatType::hp:
		Character::maxHP += amount;
		Character::curHP += amount;
		cout << "max HP increased by " << amount << endl;
		break;
	case StatType::mp:
		Character::maxMP += amount;
		Character::curMP += amount;
		cout << "max MP increased by " << amount << endl;
		break;
	case StatType::spellSlot:
		Character::spellSlots += amount;
		cout << "gained " << amount << " spell slots" << endl;
		break;
	case StatType::atk:
		Character::atk += amount;
		cout << "atk increased by " << amount << endl;
		break;
	default:
		cout << "Invalid stat type" << endl;
		break;
	}
}

void PlayerCharacter::OnDeath()
{
	IDamageable::OnDeath();
	GameManager::SetGameState(GameManager::GameState::MainMenu);
}

