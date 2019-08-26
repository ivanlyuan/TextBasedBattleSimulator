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
		MenuManager::ShopMenu();
	}
	else
	{
		BattleManager::GetPlayer()->PayGold(mo->upgrade->GetCost());
		mo->upgrade->ApplyEffect();
		ShopMenu();
	}
}

void MenuManager::ShowMenu()
{
	for (size_t i = 0; i < mos.size(); i++)
	{
		cout << i << ". " << mos[i]->text << endl;
	}

	AskForMenuInput();
	//cout << "====================" << endl;
}

void MenuManager::StartGame(MenuOption * _mo)
{
	GameManager::StartGame();
}

void MenuManager::EndGame(MenuOption* _mo)
{
	GameManager::EndGame();
}

void MenuManager::StartWave(MenuOption * mo)
{
	BattleManager::StartWave(0, BattleManager::GetPlayer());
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
	mo = new MenuOption("Exit", EndGame);
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
	ShowMenu();
}

void MenuManager::SpellSelectionMenu(MenuOption* _mo)
{
	cout << "SpellSelectionMenu()" << endl;
	BattleActionMenu(_mo);
	return;
}

void MenuManager::SpellTargetMenu(Spell* spell,IDamageable* target)
{
	mos.clear();
	MenuOption* mo;
	if (spell->GetCanTargetEnemy())
	{
		for (size_t i = 0; i < BattleManager::GetEnemies().size(); i++)
		{
			mo = new MenuOption(BattleManager::GetEnemies()[i]->GetName(), spell, BattleManager::GetEnemies()[i]);
			mos.push_back(mo);
		}
	}

	if (spell->GetCanTargetPlayer())
	{
		IDamageable* p = BattleManager::GetPlayer();
		mo = new MenuOption(p->GetName(), spell, p);
		mos.push_back(mo);
	}

	ShowMenu();
}

void SpellEffectTest(IDamageable* target)
{
	cout << "SpellEffectTest()" << endl;
}

void MenuManager::ShopMenu()
{
	cout << "=====Shop=====" << endl;
	
	
	mos.clear();
	MenuOption* mo;
	ShopUpgrade* su;

	su = new ShopUpgrade(StatType::hp, 5, 5);
	mo = new MenuOption("+5 HP", su);
	mos.push_back(mo);

	su = new ShopUpgrade(StatType::mp, 5, 5);
	mo = new MenuOption("+5 MP", su);
	mos.push_back(mo);

	su = new ShopUpgrade(StatType::spellSlot, 5, 5);
	mo = new MenuOption("+1 Spell Slot", su);
	mos.push_back(mo);


	Spell* spell = new Spell(SpellEffectTest, true, true, 5, "SpellTest");
	su = new ShopUpgrade(spell, 5);
	mo = new MenuOption("Spell: " + spell->GetName(), su);
	mos.push_back(mo);

	mo = new MenuOption("Check Stats", CheckPlayerStats);
	mos.push_back(mo);

	
	mo = new MenuOption("Leave shop", StartWave);
	mos.push_back(mo);



	ShowMenu();

	return;
}

void MenuManager::CheckBattlefield(MenuOption * mo)
{
	PlayerCharacter* p = BattleManager::GetPlayer();
	cout << p->GetName() << " HP: " << p->GetCurHP() << "/" << p->GetMaxHP() << endl;



	for (size_t i = 0; i < BattleManager::GetEnemies().size(); i++)
	{
		EnemyCharacter* e = BattleManager::GetEnemies()[i];
		if (e->IsIdentified())
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
	cout << "Spell slots: " << p->GetSpellSlots() << endl;

	ShopMenu();
}



void MenuManager::Attack(MenuOption * mo)
{
	BattleManager::GetPlayer()->Attack(mo->target);
}

void MenuManager::CastSpell(MenuOption * mo)
{
	BattleManager::GetPlayer()->CastSpell(mo->spell, mo->target);
}

void MenuManager::AskForMenuInput()
{
	//ask for input
	unsigned int i;
	if (cin >> i)//is int
	{
		if (i < mos.size())
		{
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "====================" << endl;
			mos[i]->Action(mos[i]);
			return;
		}
	}

	cout << "Invalid input, enter a number on the menu to select that option." << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	AskForMenuInput();
}
