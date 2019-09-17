#include "Shop.h"
#include "BattleManager.h"
#include "PlayerCharacter.h"
#include "SpellEffects.h"
#include <algorithm>
#include <random>
#include <ctime>

vector<ShopUpgrade*> Shop::CurUpgrades;
vector<ShopUpgrade*> Shop::AllUpgradesPool;

void Shop::InitUpgrades()
{
	AllUpgradesPool.clear();


	ShopUpgrade* su;

	su = new ShopUpgrade("HP ", StatType::hp, 5, 5);
	AllUpgradesPool.push_back(su);

	su = new ShopUpgrade("MP ", StatType::mp, 5, 5);
	AllUpgradesPool.push_back(su);

	/*
	su = new ShopUpgrade("Spell slots+1", StatType::spellSlot, 1, 5);
	AllUpgradesPool.push_back(su);
	*/

	su = new ShopUpgrade("atk", StatType::atk, 1, 5);
	AllUpgradesPool.push_back(su);
	

	Spell* fireball = new Spell(SpellEffects::DealDamage, 10, false, true, false, 7, "Fireball");
	su = new ShopUpgrade(fireball, 5);
	AllUpgradesPool.push_back(su);

	Spell* gun = new Spell(SpellEffects::DealDamage, 2, false, true, true, 5, "Joker's neutral b");
	su = new ShopUpgrade(gun, 5);
	AllUpgradesPool.push_back(su);

	Spell* quickHeal = new Spell(SpellEffects::Heal, 7, true, false, true, 10, "Quick-Heal");
	su = new ShopUpgrade(quickHeal, 5);
	AllUpgradesPool.push_back(su);

	Spell* meteor = new Spell(SpellEffects::DealDamage, 20, false, true, false, 20, "Meteor");
	su = new ShopUpgrade(meteor, 5);
	AllUpgradesPool.push_back(su);
}

void Shop::ShuffleUpgrades(int amount)
{

	CurUpgrades.clear();
	if (amount > AllUpgradesPool.size())
	{
		return;
	}

	srand(time(0));
	std::random_shuffle(AllUpgradesPool.begin(), AllUpgradesPool.end());
	for (int i = 0; i < amount; i++)
	{
		CurUpgrades.push_back(AllUpgradesPool[i]);
	}
}

void Shop::ApplyStatUpgrade(ShopUpgrade * su)
{
	BattleManager::GetPlayer()->ApplyUpgrade(su);
}

void Shop::AddSpellForPlayer(ShopUpgrade * su)
{
	BattleManager::GetPlayer()->AddSpell(su->GetSpell());//give player spell

	for (size_t i = 0; i < AllUpgradesPool.size(); i++)//remove spell from pool
	{
		if (AllUpgradesPool[i] == su)
		{
			AllUpgradesPool.erase(AllUpgradesPool.begin() + i);
			break;
		}
	}

	for (size_t i = 0; i < CurUpgrades.size(); i++)//remove spell from shop
	{
		if (CurUpgrades[i] == su)
		{
			CurUpgrades.erase(CurUpgrades.begin() + i);
			break;
		}
	}

}

void Shop::AddUpgradeToPool(ShopUpgrade * su)
{
	AllUpgradesPool.push_back(su);
}
