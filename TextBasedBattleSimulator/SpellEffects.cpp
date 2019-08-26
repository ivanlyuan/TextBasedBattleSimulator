#include "SpellEffects.h"

void SpellEffects::Fireball(IDamageable* target)
{

}

void SpellEffects::Heal(IDamageable* target)
{
	if (target)
	{
		target->Heal(10);
	}
}

void SpellEffects::Whirlwind(vector<IDamageable*> targets)
{
	for (size_t i = 0; i < targets.size(); i++)
	{
		targets[i]->TakeDamage(5);
	}
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

void SpellEffects::QuickHeal(IDamageable* target)
{
	if (target)
	{
		target->TakeDamage(5);
	}
}

void SpellEffects::Identify(EnemyCharacter* e)
{
	if (e)
	{
		e->SetIsIdentified(true);
	}
}
