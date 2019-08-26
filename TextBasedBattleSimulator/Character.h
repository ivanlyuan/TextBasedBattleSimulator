#pragma once

#include"IDamageable.h"
#include"Spell.h"
#include<string>
#include<vector>

using std::string;
using std::vector;

class Character :public IDamageable
{
public :
	Character();
	~Character();
	virtual void Attack(IDamageable* target);
	void CastSpell(Spell* s);
	void CastSpell(Spell* s, IDamageable* target);
	int GetMaxMP() { return maxMP; };
	int GetCurMP() { return curMP; };
	int GetAtk() { return atk; };
	int GetSpellSlots() { return spellSlots; };
	void Block();
	void ShowInfo();
protected:
	int maxMP;
	int curMP;
	int atk;
	int spellSlots;
	int gold;
	vector<Spell*> spells;
};