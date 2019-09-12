#include "SpellEffects.h"

void SpellEffects::DealDamage(IDamageable* target, int amount)
{
	if (target)
	{
		target->TakeDamage(amount);
	}
}

void SpellEffects::Heal(IDamageable* target, int amount)
{
	if (target)
	{
		target->Heal(amount);
	}
}

