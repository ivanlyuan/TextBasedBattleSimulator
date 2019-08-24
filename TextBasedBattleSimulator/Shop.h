#pragma once
#include "Spell.h"
#include "PlayerCharacter.h"
#include "ShopUpgrade.h"
#include <vector>

using std::vector;

enum StatType
{
	hp, mp, atk, spellSlot
};




class Shop
{
public:
	static void ShuffleUpgrades();
	static void ApplyStatUpgrade(ShopUpgrade* su);
	static void AddSpell(ShopUpgrade* su);
private:
	Shop();
	vector<ShopUpgrade*> Upgrades;
	
};