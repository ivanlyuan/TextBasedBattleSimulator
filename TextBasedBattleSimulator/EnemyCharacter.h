#pragma once
#include "Character.h"

class EnemyCharacter: public Character
{
public:
	EnemyCharacter();
	EnemyCharacter(string _name);
	~EnemyCharacter();
	void OnDeath() override;
	bool IsIdentified() { return isIdentified; };
private:
	bool isIdentified;

};