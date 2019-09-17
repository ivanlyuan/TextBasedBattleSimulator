#include"MenuManager.h"
#include "Shop.h"
#include "ShopUpgrade.h"
#include "IDamageable.h"
#include <ios>

using std::cin;

vector<MenuOption*> MenuManager::mos;

void MenuManager::BuyUpgrade(MenuOption * mo)
{
	if (mo->upgrade->GetCost() > BattleManager::GetPlayer()->GetGold())
	{
		cout << "Not enough gold" << endl;
	}
	else
	{
		BattleManager::GetPlayer()->PayGold(mo->upgrade->GetCost());
		mo->upgrade->ApplyEffect();

	}
	ShopMenu();
}

void MenuManager::ShowMenu()
{
	for (size_t i = 0; i < mos.size(); i++)
	{
		cout << i << ". " << mos[i]->text << endl;
	}

	int i = -1;
	while (i==-1)
	{
		i = AskForMenuInput();
	}
	mos[i]->Action(mos[i]);
}

void MenuManager::StartGame(MenuOption * _mo)
{
	GameManager::StartGame();
}

void MenuManager::ExitGame(MenuOption* _mo)
{
	exit(0);
}

void MenuManager::LeaveShop(MenuOption * mo)
{
	GameManager::NextLevel();
	GameManager::SetGameState(GameManager::GameState::Battle);
}

void MenuManager::MainMenu(MenuOption* _mo)//shortcut
{
	MainMenu();
}

void MenuManager::MainMenu()
{
	mos.clear();

	MenuOption* mo;
	mo = new MenuOption("Start Game", StartGame);
	mos.push_back(mo);
	mo = new MenuOption("Exit", ExitGame);
	mos.push_back(mo);

	ShowMenu();
}

void MenuManager::BattleActionMenu(MenuOption* _mo)
{
	BattleActionMenu();
}

void MenuManager::BattleActionMenu()
{
	mos.clear();
	MenuOption* mo;
	mo = new MenuOption("Attack", AttackTargetMenu);
	mos.push_back(mo);
	mo = new MenuOption("Spell", SpellSelectionMenu);
	mos.push_back(mo);
	/*not finished
	mo = new MenuOption("Block", Block);
	mos.push_back(mo);
	*/
	mo = new MenuOption("Check Battlefield", CheckBattlefield);
	mos.push_back(mo);

	mo = new MenuOption("Check Player Stats", CheckPlayerStats);
	mos.push_back(mo);

	ShowMenu();
}

void MenuManager::AttackTargetMenu(MenuOption* _mo)
{
	mos.clear();
	MenuOption* mo;
	for (size_t i = 0; i < BattleManager::GetEnemies().size(); i++)
	{
		mo = new MenuOption(BattleManager::GetEnemies()[i]->GetName(), BattleManager::GetEnemies()[i]);
		mos.push_back(mo);
	}
	mo = new MenuOption("Back", BattleActionMenu);
	mos.push_back(mo);
	ShowMenu();
}

void MenuManager::SpellSelectionMenu(MenuOption* _mo)
{
	mos.clear();

	vector<Spell*> spells = BattleManager::GetPlayer()->GetSpells();
	if (spells.size() == 0)
	{
		cout << "No spells available" << endl;
		BattleActionMenu();
		return;
	}


	MenuOption* mo;
	for (size_t i = 0; i < spells.size(); i++)
	{
		mo = new MenuOption(spells[i]->GetName(), spells[i]);
		mos.push_back(mo);
	}
	mo = new MenuOption("Back", BattleActionMenu);
	mos.push_back(mo);

	ShowMenu();
}

void MenuManager::SpellTargetMenu(MenuOption* mo)
{
	mos.clear();
	MenuOption* _mo;
	if (mo->spell->GetCanTargetEnemy())
	{
		for (size_t i = 0; i < BattleManager::GetEnemies().size(); i++)
		{
			_mo = new MenuOption(BattleManager::GetEnemies()[i]->GetName(), mo->spell, BattleManager::GetEnemies()[i]);
			mos.push_back(_mo);
		}
	}

	if (mo->spell->GetCanTargetPlayer())
	{
		IDamageable* p = BattleManager::GetPlayer();
		_mo = new MenuOption(p->GetName(), mo->spell, p);
		mos.push_back(_mo);
	}

	mo = new MenuOption("Back", BattleActionMenu);
	mos.push_back(mo);

	ShowMenu();
}

void MenuManager::ShopMenu()
{
	cout << "==========Shop==========" << endl;
	
	
	mos.clear();
	MenuOption* mo;
	ShopUpgrade* su;

	for (size_t i = 0; i < Shop::GetCurUpgrades().size(); i++)
	{
		su = Shop::GetCurUpgrades()[i];
		mo = new MenuOption(su->GetName() + "	" + std::to_string(su->GetCost()) + "g", su);
		mos.push_back(mo);
	}
	mo = new MenuOption("Check Stats", CheckPlayerStats);
	mos.push_back(mo);

	
	mo = new MenuOption("Leave shop", LeaveShop);
	mos.push_back(mo);



	ShowMenu();

	return;
}

void MenuManager::CheckBattlefield(MenuOption * mo)
{
	PlayerCharacter* p = BattleManager::GetPlayer();
	cout << p->GetName() << " HP: " << p->GetCurHP() << "/" << p->GetMaxHP() << " MP: " << p->GetCurMP() << "/" << p->GetMaxMP() << endl;


	for (size_t i = 0; i < BattleManager::GetEnemies().size(); i++)
	{
		EnemyCharacter* e = BattleManager::GetEnemies()[i];
		if (e->GetIsIdentified())
		{
			cout << e->GetName() << " HP: " << e->GetCurHP() << "/" << e->GetMaxHP() << endl;
		}
	}

	BattleActionMenu();
}

void MenuManager::CheckPlayerStats(MenuOption * mo)
{
	PlayerCharacter* p = BattleManager::GetPlayer();
	cout << p->GetName() << endl;
	cout << "HP: " << p->GetCurHP() << "/" << p->GetMaxHP() << endl;
	cout << "MP: " << p->GetCurMP() << "/" << p->GetMaxMP() << endl;
	cout << "Atk: " << p->GetAtk() << endl;
	cout << "Gold: " << p->GetGold() << endl;
	//cout << "Spell slots: " << p->GetSpellSlots() << endl;
	cout << "Spells: " << endl;

	for (size_t i = 0; i < p->GetSpells().size(); i++)
	{
		if (p->GetSpells()[i])
		{
			cout << p->GetSpells()[i]->GetName() << endl;
		}
	}

	ShopMenu();
}



void MenuManager::Attack(MenuOption * mo)
{
	BattleManager::GetPlayer()->Attack(mo->target);
}

void MenuManager::CastSpell(MenuOption * mo)
{
	if (!BattleManager::GetPlayer()->CastSpell(mo->spell, mo->target) || mo->spell->GetIsQuick())
	{
		BattleActionMenu();
	}
}

int MenuManager::AskForMenuInput()
{
	//ask for input
	unsigned int i;
	if (cin >> i)//is int
	{
		if (i < mos.size())
		{
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "================================================================================" << endl;
			return i;
		}
	}

	cout << "Invalid input, enter a number on the menu to select that option." << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return -1;
}
