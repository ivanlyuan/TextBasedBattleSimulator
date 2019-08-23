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
	void OnDeath() override;
};
