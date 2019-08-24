#include "Shop.h"


ShopUpgrade::ShopUpgrade(StatType type, int _amount, unsigned int _cost)
{
	cost = _cost;
	amount = _amount;
	Effect = Shop::ApplyStatUpgrade;

}

ShopUpgrade::ShopUpgrade(Spell * _spell, unsigned int _cost)
{
	cost = _cost;
	Effect = Shop::AddSpell;
}



void ShopUpgrade::ApplyEffect()
{
	Effect(this);
}