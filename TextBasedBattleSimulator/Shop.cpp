#include "Shop.h"
#include "BattleManager.h"
#include "PlayerCharacter.h"
#include <algorithm>

vector<ShopUpgrade*> Shop::CurUpgrades;
vector<ShopUpgrade*> Shop::AllUpgradesPool;

void Shop::InitUpgrades()
{
	ShopUpgrade* su;

	su = new ShopUpgrade("HP+5", StatType::hp, 5, 5);
	AllUpgradesPool.push_back(su);

	su = new ShopUpgrade("MP+5", StatType::mp, 5, 5);
	AllUpgradesPool.push_back(su);

	su = new ShopUpgrade("Spell slots+1", StatType::spellSlot, 5, 5);
	AllUpgradesPool.push_back(su);
}

void Shop::ShuffleUpgrades(int amount)
{

	CurUpgrades.clear();
	if (amount > AllUpgradesPool.size())
	{
		return;
	}


	for (int i = 0; i < amount; i++)
	{
		//std::random_shuffle(AllUpgradesPool.begin(), AllUpgradesPool.end());
		CurUpgrades.push_back(AllUpgradesPool[i]);
	}
}

void Shop::ApplyStatUpgrade(ShopUpgrade * su)
{
	BattleManager::GetPlayer()->ApplyUpgrade(su);
}

void Shop::AddSpellForPlayer(ShopUpgrade * su)
{
	BattleManager::GetPlayer()->AddSpell(su->GetSpell());
}

void Shop::AddUpgradeToPool(ShopUpgrade * su)
{
	AllUpgradesPool.push_back(su);
}
