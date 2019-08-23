#pragma once
#include "Spell.h"

struct ShopUpgrade
{
public:
	int GetCost() { return cost; };
private:
	int cost;
};

struct StatUpgrade
{
	unsigned int hp;
	unsigned int mp;
	unsigned int atk;
	unsigned int spellSlot;
};

struct SpellUpgrade
{
	Spell* spell;
};

class Shop
{
public:
	Shop();
	~Shop();
	void ShuffleUpgrades();
private:
	ShopUpgrade * Upgrades;
	
};