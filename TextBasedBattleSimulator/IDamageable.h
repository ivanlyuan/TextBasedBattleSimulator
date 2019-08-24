#pragma once
#include "IHasName.h"

class IDamageable : public IHasName
{
public:
	void TakeDamage(int amount);
	void Heal(int amount);
	int GetMaxHP() { return maxHP; };
	int GetCurHP() { return curHP; };
	virtual void OnDeath();
protected:
	int maxHP;
	int curHP;
};