#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <vector>

class Table;
class Player;

class GameManager
{
public:
	

	GameManager();
	virtual ~GameManager();

	//void CreateTable( const GameManager::Rules_t& rules );

	void StartGame();

	static GameManager* GetInstance();
private:

	std::vector< Table* > mpTables;
	std::vector< Player* > mpPlayers;

	static GameManager* mpInstance;


};

#endif

