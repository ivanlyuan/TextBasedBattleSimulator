#include "SpellEffects.h"

void SpellEffects::Fireball(IDamageable* target)
{
	if (target)
	{
		target->TakeDamage(8);
	}
}

void SpellEffects::Heal(IDamageable* target)
{
	if (target)
	{
		target->Heal(10);
	}
}

void SpellEffects::Whirlwind(IDamageable* target)
{

}

void SpellEffects::Drain(IDamageable* target,IDamageable* self)
{
	if (target)
	{
		target->TakeDamage(5);
	}

	if (self)
	{
		self->Heal(5);
	}
}

void SpellEffects::Identify(EnemyCharacter* e)
{
	if (e)
	{
		e->SetIsIdentified(true);
	}
}
