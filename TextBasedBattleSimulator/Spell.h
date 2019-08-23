#pragma once
#include<iostream>
#include<string>
#include"IHasName.h"
#include"IDamageable.h"

using std::cout;
using std::endl;
using std::string;

class Spell :public IHasName
{
public:
	Spell(void(*_Effect)(IDamageable* target), bool _canTargetAlly, bool _canTargetEnemy, int _cost, string _name);
	~Spell();
	void ApplyEffect();
	void ApplyEffect(IDamageable* target);
	bool GetCanTargetPlayer() { return canTargetPlayer; };
	bool GetCanTargetEnemy() { return canTargetEnemy; };
private:
	bool canTargetPlayer;
	bool canTargetEnemy;
	int cost;
	void(*Effect)(IDamageable* target);
};

