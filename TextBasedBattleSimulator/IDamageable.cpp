#include <iostream>
#include "IDamageable.h"

using std::cout;
using std::endl;

void IDamageable::TakeDamage(int amount)
{
	if (!isAlive)
	{
		cout << name << "is already dead!" << endl;
		return;
	}

	curHP -= amount;
	cout << name << " took " << amount << " damage!" << endl;

	if (curHP <= 0)
	{
		OnDeath();
	}

}

void IDamageable::Heal(int amount)
{
	if (!isAlive)
	{
		cout << name << "is already dead!" << endl;
		return;
	}

	int prevHP = curHP;
	if (curHP + amount > maxHP)
	{
		curHP = maxHP;
		cout << name << " restored " << curHP - prevHP << " health!" << endl;
	}
	else
	{
		curHP += amount;
		cout << name << " restored " << amount << " health!" << endl;
	}
}

void IDamageable::OnDeath()
{
	isAlive = false;
	cout << name << " died!" << endl;
}
