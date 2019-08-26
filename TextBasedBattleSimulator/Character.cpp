#include<iostream>
#include "Character.h"

using std::cout;
using std::endl;

Character::Character()
{
	name = "characterName";
	maxHP = 10;
	curHP = 10;
	atk = 3;
}

Character::~Character()
{
	cout << "Destroyed character! name = " << name << endl;
}


void Character::Attack(IDamageable* target)
{
	if (target != nullptr)
	{
		cout << name << " attacked " << target->GetName() << endl;
		target->TakeDamage(atk);
	}
	else
	{
		cout << "Attack failed: target not found" << endl;
	}

}

void Character::CastSpell(Spell *s)
{
	cout << name << " casted " << s->GetName() << endl;
	s->ApplyEffect();
}

void Character::CastSpell(Spell *s, IDamageable* target)
{
	cout << name << " casted " << s->GetName() << " on " << target->GetName() << endl;
	s->ApplyEffect(target);
}

void Character::Block()
{
	cout << name << " Block()" << endl;
}

void Character::ShowInfo()
{
	cout << "Name: " << name << endl;
	cout << " HP: " << curHP << "/" << "maxHP" << endl;
}
