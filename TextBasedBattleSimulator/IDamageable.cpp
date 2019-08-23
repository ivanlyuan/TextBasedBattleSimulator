#include <iostream>
#include "IDamageable.h"

using std::cout;
using std::endl;

void IDamageable::TakeDamage(int amount)
{
	curHP -= amount;
	cout << name << " took " << amount << " damage!" << endl;

	if (curHP <= 0)
	{
		OnDeath();
	}

}

void IDamageable::Heal(int amount)
{
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
	cout << name << " died!" << endl;
}
