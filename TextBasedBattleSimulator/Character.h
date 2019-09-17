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
	bool CastSpell(Spell* s);
	bool CastSpell(Spell* s, IDamageable* target);
	int GetMaxMP() { return maxMP; };
	int GetCurMP() { return curMP; };
	int GetAtk() { return atk; };
	int GetSpellSlots() { return spellSlots; };
	vector<Spell*> GetSpells() { return spells; };
	void Block();
	void ShowInfo();
	void FullRestore() { curHP = maxHP; curMP = maxMP; };
protected:
	int maxMP;
	int curMP;
	int atk;
	int spellSlots;
	int gold;
	vector<Spell*> spells;
};