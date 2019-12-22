#pragma once

#include<string>
#include "Character.h"
#include "Spell.h"
#include "IHasName.h"
#include "Shop.h"
#include "ShopUpgrade.h"


class PlayerCharacter :public Character
{
public:
	PlayerCharacter();
	PlayerCharacter(string _name);
	~PlayerCharacter();
	bool Attack(IDamageable* target)override;
	void ObtainGold(int amount);
	void ApplyUpgrade(ShopUpgrade* su);
	void AddSpell(Spell* spell) { cout << "Added spell: " << spell->GetName() << endl; spells.push_back(spell); };
	void OnDeath() override;
	int GetGold() { return gold; };
	void PayGold(int amount) { cout << "Paid " << amount << " gold" << endl; gold -= amount; };
};
