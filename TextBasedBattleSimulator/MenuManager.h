#pragma once
#include"GameManager.h"
#include<vector>

using std::vector;

struct MenuOption
{
	MenuOption(string t, void(*action)()) { text = t; Action = action; };
	MenuOption(string t, Spell* _spell, IDamageable *_target) { text = t; spell = _spell; target = _target; };

	string text;
	void(*Action)();
	Spell* spell;
	IDamageable* target;
private:

};


class MenuManager
{
public:
	static void MainMenu();
	static void SpellTargetMenu(Spell* spell, IDamageable* target);
	static Spell* GetCurSpell() { return curSpell; };
	static void AskForInput();
private:
	MenuManager();
	static void ShowMenu();
	static vector<MenuOption*> mos;
	static Spell* curSpell;

};