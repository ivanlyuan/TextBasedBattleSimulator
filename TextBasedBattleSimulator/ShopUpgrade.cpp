#include "Shop.h"


ShopUpgrade::ShopUpgrade(string _name, StatType _statType, int _amount, int _cost)
{

	cost = _cost;
	amount = _amount;
	statType = _statType;
	Effect = Shop::ApplyStatUpgrade;
	name = "STAT BOOST: " + _name + "+" + std::to_string(amount);

}

ShopUpgrade::ShopUpgrade(Spell * _spell, int _cost)
{
	name = "SPELL: " + _spell->GetName();
	cost = _cost;
	spell = _spell;
	Effect = Shop::AddSpellForPlayer;
}



void ShopUpgrade::ApplyEffect()
{
	Effect(this);
}