#pragma once

#include<string>
#include "Character.h"
#include "Spell.h"
#include "IHasName.h"

class PlayerCharacter :public Character
{
public:
	PlayerCharacter();
	PlayerCharacter(string _name);
	~PlayerCharacter();
	void Attack(IDamageable* target)override;
	void ObtainGold(int amount);
	void IncreaseHP(int amount) { maxHP += amount; curHP += amount; };
	void IncreaseMP(int amount) { maxMP += amount; curMP += amount; };
	void IncreaseSpellSlots(int amount) { spellSlots += amount; };
	void AddSpell(Spell* spell) { spells.push_back(spell); };
	void OnDeath() override;
	int GetGold() { return gold; };
};
