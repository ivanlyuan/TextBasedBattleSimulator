#include "MenuOption.h"

MenuOption::MenuOption(string t, void(*action)(MenuOption* mo))
{
	text = t;
	Action = action;
}

MenuOption::MenuOption(string t, IDamageable * attackTarget)
{
	text = t;
	target = attackTarget;
	Action = MenuManager::Attack;
}

MenuOption::MenuOption(string t, Spell * _spell, IDamageable * spellTarget)
{
	text = t;
	spell = _spell;
	target = spellTarget;
	Action = MenuManager::CastSpell;
}

MenuOption::MenuOption(string t, ShopUpgrade* su)
{
	text = t;
	upgrade = su;
	Action = MenuManager::BuyUpgrade;
}
