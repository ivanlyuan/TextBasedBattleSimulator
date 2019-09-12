#include "Spell.h"

Spell::Spell(void(*_Effect)(IDamageable* target, int amount), int _amount, bool _canTargetPlayer, bool _canTargetEnemy, int _cost, string _name)
	:Effect(*_Effect), amount(_amount), canTargetPlayer(_canTargetPlayer), canTargetEnemy(_canTargetEnemy), cost(_cost)
{
	name = _name;
}

Spell::~Spell()
{

}

void Spell::ApplyEffect()
{
	cout << "Applied " << name << "'s effect" << endl;
}

void Spell::ApplyEffect(IDamageable * target)
{
	cout << "Applied " << name << "'s effect on " << target->GetName() << endl;
	Effect(target, amount);
}

