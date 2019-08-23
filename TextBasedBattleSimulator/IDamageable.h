#pragma once
#include "IHasName.h"

class IDamageable : public IHasName
{
public:
	void TakeDamage(int amount);
	void Heal(int amount);
	virtual void OnDeath();
protected:
	int maxHP;
	int curHP;
};