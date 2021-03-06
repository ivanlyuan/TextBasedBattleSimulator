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


bool Character::Attack(IDamageable* target)
{
	if (target != NULL)
	{
		//cout << name << " attacked " << target->GetName() << endl;
		target->TakeDamage(atk);
		hasAttacked = true;
		return true;
	}
	else
	{
		cout << "Attack failed: target not found" << endl;
		return false;
	}

}

bool Character::CastSpell(Spell *s)
{
	if (curMP < s->GetManaCost())
	{
		cout << "Not enough mp to cast " << s->GetName() << "!" << endl;
		return false;
	}

	curMP -= s->GetManaCost();
	cout << name << " casted " << s->GetName() << endl;
	s->ApplyEffect();
	hasAttacked = true;
	return true;
}

bool Character::CastSpell(Spell *s, IDamageable* target)
{
	if (curMP < s->GetManaCost())
	{
		cout << "Not enough mp to cast " << s->GetName() << "!" << endl;
		return false;
	}

	curMP -= s->GetManaCost();
	cout << name << " casted " << s->GetName() << " on " << target->GetName() << endl;
	s->ApplyEffect(target);
	hasAttacked = true;
	return true;
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
