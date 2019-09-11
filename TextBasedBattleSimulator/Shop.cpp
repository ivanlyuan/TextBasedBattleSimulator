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
	ShopUpgrade* su;

	su = new ShopUpgrade("HP+5", StatType::hp, 5, 5);
	AllUpgradesPool.push_back(su);

	su = new ShopUpgrade("MP+5", StatType::mp, 5, 5);
	AllUpgradesPool.push_back(su);

	su = new ShopUpgrade("Spell slots+1", StatType::spellSlot, 5, 5);
	AllUpgradesPool.push_back(su);

	Spell* fireball = new Spell(SpellEffects::Fireball, false, true, 3, "Fireball");
	su = new ShopUpgrade("Spell: Fireball", fireball, 5);
	AllUpgradesPool.push_back(su);

	Spell* whirlwind = new Spell(SpellEffects::Whirlwind, false, true, 5, "Whirlwind");
	su = new ShopUpgrade("Spell: Whirlwind", whirlwind, 5);
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
	BattleManager::GetPlayer()->AddSpell(su->GetSpell());
}

void Shop::AddUpgradeToPool(ShopUpgrade * su)
{
	AllUpgradesPool.push_back(su);
}
