#pragma once
#include "Character.h"

class EnemyCharacter: public Character
{
public:

	enum EnemyType
	{
		solider,
		mage,
		eliteSolider,
		archmage,
		champion
	};


	EnemyCharacter();
	EnemyCharacter(string _name);
	EnemyCharacter(EnemyType et);
	~EnemyCharacter();
	void OnDeath() override;
	bool GetIsIdentified() { return isIdentified; };
	void SetIsIdentified(bool b) { isIdentified = b; };
private:
	bool isIdentified;

};