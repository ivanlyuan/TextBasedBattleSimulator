#include"PlayerCharacter.h"
#include "GameManager.h"
#include "BattleManager.h"

PlayerCharacter::PlayerCharacter()
{
	maxHP = 20;
	curHP = 20;
	maxMP = 10;
	curMP = 10;
	atk = 5;
	name = "Player";
}

PlayerCharacter::PlayerCharacter(string _name)
{
	maxHP = 20;
	curHP = 20;
	maxMP = 10;
	curMP = 10;
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
		cout << "max HP increaced by " << amount << endl;
		break;
	case StatType::mp:
		Character::maxMP += amount;
		Character::curMP += amount;
		cout << "max MP increaced by " << amount << endl;
		break;
	case StatType::spellSlot:
		Character::spellSlots += amount;
		cout << "gained " << amount << " spell slots" << endl;
		break;
	case StatType::atk:
		Character::atk += amount;
		cout << "atk increaced by " << amount << endl;
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
	GameManager::SetGameState(GameManager::GameState::MainMenu);
}

