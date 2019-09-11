#pragma once
#include "EnemyCharacter.h"

namespace SpellEffects
{
	void Fireball(IDamageable* target);
	void Heal(IDamageable* target);
	void Whirlwind(IDamageable* target);
	void Drain(IDamageable* target, IDamageable* self);
	void Identify(EnemyCharacter* e);
}