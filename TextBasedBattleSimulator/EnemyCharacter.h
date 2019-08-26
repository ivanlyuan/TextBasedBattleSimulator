#pragma once
#include "Character.h"

class EnemyCharacter: public Character
{
public:
	EnemyCharacter();
	EnemyCharacter(string _name);
	~EnemyCharacter();
	void OnDeath() override;
	bool GetIsIdentified() { return isIdentified; };
	void SetIsIdentified(bool b) { isIdentified = b; };
private:
	bool isIdentified;

};