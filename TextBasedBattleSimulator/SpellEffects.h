#pragma once
#include "EnemyCharacter.h"

namespace SpellEffects
{
	static void Fireball(IDamageable* target);
	static void Heal(IDamageable* target);
	static void Whirlwind(vector<IDamageable*> targets);
	static void Drain(IDamageable* target, IDamageable* self);
	static void QuickHeal(IDamageable* target);
	static void Identify(EnemyCharacter* e);
}