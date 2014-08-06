#include "gamemanager.h"

#include "table.h"
#include "player.h"
#include "dealer.h"
#include "composition.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	for ( std::vector< Table* >::iterator iter = mTables.begin();
		iter != mTables.end();
		++iter )
	{
		delete *iter;
		*iter = NULL;
	}

	mTables.clear();
}

void GameManager::CreateTable( const GameManager::Rules_t& rules )
{
	Table* table = new Table();
	Composition* composition = new Composition( rules.numOfDecks );

	table->SetCards( composition );

	for ( int i = 0; i < rules.numOfPlayers; ++i )
	{
		table->AddPlayer( new Player() );
	}

	mTables.push_back( table );
}