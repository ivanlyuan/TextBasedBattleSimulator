#include"MenuManager.h"
#include"BattleManager.h"

using std::cin;

vector<MenuOption*> MenuManager::mos;

void MenuManager::ShowMenu()
{
	for (size_t i = 0; i < mos.size(); i++)
	{
		cout << i << ". " << mos[i]->text << endl;
	}

}

void MenuManager::MainMenu()
{
	mos.clear();

	MenuOption* mo;
	mo = new MenuOption("Start Game", GameManager::StartGame);
	mos.push_back(mo);
	mo = new MenuOption("Exit", GameManager::EndGame);
	mos.push_back(mo);

	ShowMenu();
}

void MenuManager::SpellTargetMenu(Spell* spell,IDamageable* target)
{
	mos.clear();
	MenuOption* mo;
	if (spell->GetCanTargetEnemy())
	{
		for (size_t i = 0; i < BattleManager::GetEnemies().size(); i++)
		{
			mo = new MenuOption(BattleManager::GetEnemies()[i]->GetName(), spell, target);
			mos.push_back(mo);
		}
	}
	if (spell->GetCanTargetPlayer())
	{
		for (size_t i = 0; i < BattleManager::GetEnemies().size(); i++)
		{
			mo = new MenuOption(BattleManager::GetEnemies()[i]->GetName(), spell, target);
			mos.push_back(mo);
		}
	}

	ShowMenu();
}

void MenuManager::AskForInput()
{
	//ask for input
	int i;
	cin >> i;
	//perform the menu option
	//
	cout << i << endl;
	



}
