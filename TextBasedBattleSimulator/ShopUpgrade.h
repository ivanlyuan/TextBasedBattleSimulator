#pragma once
#include "Shop.h"

enum StatType;

class ShopUpgrade :public IHasName
{
public:

	ShopUpgrade(string _name,StatType type, int _amount, unsigned int _cost);
	ShopUpgrade(Spell* _spell, unsigned int _cost);
	unsigned int GetCost() { return cost; };
	Spell* GetSpell() { return spell; };
	StatType GetStatType() { return statType; };
	unsigned int GetAmount() { return amount; };
	void ApplyEffect();

private:
	StatType statType;
	unsigned int amount;
	Spell* spell;
	void(*Effect)(ShopUpgrade* su);
	unsigned int cost;
};