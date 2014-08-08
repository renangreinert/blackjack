#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <vector>

class Table;
class Player;

class GameManager
{
public:
	struct Rules_t
	{
		int numOfDecks;
		int numOfPlayers;
	};

	GameManager();
	virtual ~GameManager();

	void CreateTable( const GameManager::Rules_t& rules );

	void StartGame();
private:

	std::vector< Table* > mpTables;
	std::vector< Player* > mpPlayers;

};

#endif

