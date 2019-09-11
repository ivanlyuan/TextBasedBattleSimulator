#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"IDamageable.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Spell :public IHasName
{
public:
	Spell(void(*_Effect)(IDamageable* target), bool _canTargetAlly, bool _canTargetEnemy, int _cost, string _name);
	~Spell();
	void ApplyEffect();
	void ApplyEffect(IDamageable* target);
	bool GetCanTargetPlayer() { return canTargetPlayer; };
	bool GetCanTargetEnemy() { return canTargetEnemy; };
	IDamageable* GetTarget() { return target; };
private:
	bool canTargetPlayer;
	bool canTargetEnemy;
	int cost;
	IDamageable* target;
	void(*Effect)(IDamageable* target);
};

