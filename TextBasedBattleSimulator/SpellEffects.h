#pragma once
#include "EnemyCharacter.h"

namespace SpellEffects
{
	void DealDamage(IDamageable* target, int amount);
	void Heal(IDamageable* target,int amount);
}