#include "Shop.h"


ShopUpgrade::ShopUpgrade(string _name,StatType type, int _amount, unsigned int _cost)
{
	name = _name;
	cost = _cost;
	amount = _amount;
	Effect = Shop::ApplyStatUpgrade;

}

ShopUpgrade::ShopUpgrade(string _name,Spell * _spell, unsigned int _cost)
{
	name = _name;
	cost = _cost;
	spell = _spell;
	Effect = Shop::AddSpellForPlayer;
}



void ShopUpgrade::ApplyEffect()
{
	Effect(this);
}