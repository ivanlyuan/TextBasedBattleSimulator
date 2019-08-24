#include "Shop.h"
#include "BattleManager.h"
#include "PlayerCharacter.h"


void Shop::ApplyStatUpgrade(ShopUpgrade * su)
{
	BattleManager::GetPlayer()->ApplyUpgrade(su);
}

void Shop::AddSpell(ShopUpgrade * su)
{
	BattleManager::GetPlayer()->AddSpell(su->GetSpell());
}
