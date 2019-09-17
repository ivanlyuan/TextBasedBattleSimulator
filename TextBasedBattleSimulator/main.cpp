#include "GameManager.h"
#include "MenuManager.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"
#include "LevelManager.h"

using std::string;
using std::cout;
using std::cin;

int main()
{
	GameManager::SetGameState(GameManager::GameState::MainMenu);

	while (true)
	{
		MenuManager::MainMenu();
	}
	return 0;

}