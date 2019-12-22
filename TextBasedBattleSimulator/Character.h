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
	virtual bool Attack(IDamageable* target);
	bool CastSpell(Spell* s);
	bool CastSpell(Spell* s, IDamageable* target);
	int GetMaxMP() { return maxMP; };
	int GetCurMP() { return curMP; };
	int GetAtk() { return atk; };
	bool GetHasAttacked() { return hasAttacked; };
	int GetSpellSlots() { return spellSlots; };
	vector<Spell*> GetSpells() { return spells; };
	void Block();
	void ShowInfo();
	void SetHasAttacked(bool b) { hasAttacked = b; };
	void FullRestore() { curHP = maxHP; curMP = maxMP; };
protected:
	int maxMP;
	int curMP;
	int atk;
	int spellSlots;
	int gold;
	bool hasAttacked;
	vector<Spell*> spells;
};