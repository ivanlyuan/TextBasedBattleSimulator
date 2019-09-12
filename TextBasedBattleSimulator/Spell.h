#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"IDamageable.h"

class Character;

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Spell :public IHasName
{
public:
	Spell(void(*_Effect)(IDamageable* target, int amount), int _amount, bool _canTargetAlly, bool _canTargetEnemy, int _cost, string _name);
	~Spell();
	void ApplyEffect();
	void ApplyEffect(IDamageable* target);
	bool GetCanTargetPlayer() { return canTargetPlayer; };
	bool GetCanTargetEnemy() { return canTargetEnemy; };
	IDamageable* GetTarget() { return target; };
	void SetOwner(Character* c) { owner = c; };
private:
	bool canTargetPlayer;
	bool canTargetEnemy;
	int cost;
	int amount;
	IDamageable* target;
	Character* owner;
	void(*Effect)(IDamageable* target, int amount);
};

