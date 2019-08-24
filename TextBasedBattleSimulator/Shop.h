#pragma once
#include "Spell.h"
#include "PlayerCharacter.h"
#include <vector>

using std::vector;

class ShopUpgrade
{
public:
	enum UpgradeType
	{
		pUpgrade, mpUpgrade, atkUpgrade, spellSlotUpgrade, spellUpgrade
	};
	ShopUpgrade(UpgradeType type);
	int GetCost() { return cost; };
	void Apply(PlayerCharacter* c);

private:
	string name;
	unsigned int amount;
	Spell* spell;
	void(*Effect)(PlayerCharacter* c);
	unsigned int cost;
};

class Shop
{
public:
	Shop();
	~Shop();
	void ShuffleUpgrades();
private:
	vector<ShopUpgrade*> Upgrades;
	
};