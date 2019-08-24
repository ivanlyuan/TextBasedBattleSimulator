#pragma once
#include"GameManager.h"
#include"BattleManager.h"
#include "MenuOption.h"
#include<vector>

using std::vector;

class MenuOption;

class MenuManager
{
public:
	//start/end game
	static void StartGame(MenuOption* _mo);
	static void EndGame(MenuOption* _mo);
	//call menu
	static void MainMenu(MenuOption* _mo);
	static void MainMenu();
	static void BattleActionMenu(MenuOption* _mo);
	static void BattleActionMenu();
	static void AttackTargetMenu(MenuOption* _mo);
	static void SpellSelectionMenu(MenuOption* _mo);
	static void SpellTargetMenu(Spell* spell, IDamageable* target);
	static void ShopMenu();
	//battle actions
	static void Attack(MenuOption* mo);
	static void CastSpell(MenuOption* mo);
	static void Block(MenuOption* _mo)
	{
		BattleManager::GetPlayer()->Block();//not finished
		BattleActionMenu(_mo);
	};
	//shop upgrades
	static void BuyUpgrade(MenuOption* mo);


private:
	MenuManager();
	static void ShowMenu();
	static void AskForMenuInput();
	static vector<MenuOption*> mos;

};


