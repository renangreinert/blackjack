#include "gamemanager.h"

int main()
{
	GameManager* gameManager = new GameManager();

	gameManager->StartGame();

	delete gameManager;
	return 0;
}


