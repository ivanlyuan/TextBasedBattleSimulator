#pragma once
#include "MenuManager.h"
#include "Shop.h"
class MenuManager;


class MenuOption
{
public:
	MenuOption(string t, void(*action)(MenuOption* mo));//no parameter
	MenuOption(string t, IDamageable *attackTarget);//attack
	MenuOption(string t, Spell* _spell, IDamageable *spellTarget);//cast spell
	MenuOption(string t, ShopUpgrade* su);//buy upgrade

	string text;
	IDamageable* target;
	Spell* spell;
	ShopUpgrade* upgrade;
	void(*Action)(MenuOption*);
private:


};
