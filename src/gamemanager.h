#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <vector>

class Table;

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
private:

	std::vector< Table* > mTables;

};

#endif

