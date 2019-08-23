#pragma once

#include"IDamageable.h"
#include"Spell.h"
#include<string>

using std::string;

class Character :public IDamageable
{
public :
	Character();
	~Character();
	virtual void Attack(IDamageable* target);
	void CastSpell(Spell* s);
	void CastSpell(Spell* s, IDamageable* target);
	void ShowInfo();
protected:
	int atk;
	int gold;
};