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
	static void InitUpgrades();
	static void ShuffleUpgrades(int amount);
	static void ApplyStatUpgrade(ShopUpgrade* su);
	static void AddSpellForPlayer(ShopUpgrade* su);
	static void AddUpgradeToPool(ShopUpgrade* su);
	static vector<ShopUpgrade*> GetCurUpgrades() { return CurUpgrades; };
private:
	Shop();
	static vector<ShopUpgrade*> CurUpgrades;//changes per level
	static vector<ShopUpgrade*> AllUpgradesPool;//adds new spells per level
	
};