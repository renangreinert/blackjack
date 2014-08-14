#include "gamemanager.h"

#include "table.h"
#include "player.h"
#include "dealer.h"
#include "composition.h"

GameManager* GameManager::mpInstance = NULL;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	for ( std::vector< Table* >::iterator iter = mpTables.begin();
		iter != mpTables.end();
		++iter )
	{
		delete *iter;
		*iter = NULL;
	}

	mpTables.clear();

	for ( std::vector< Player* >::iterator iter = mpPlayers.begin();
		iter != mpPlayers.end();
		++iter )
	{
		delete *iter;
		*iter = NULL;
	}

	mpPlayers.clear();
}

GameManager* GameManager::GetInstance()
{
	if ( mpInstance == NULL )
	{
		mpInstance = new GameManager();
	}
	return mpInstance;
}

/*void GameManager::CreateTable( const GameManager::Rules_t& rules )
{
	//TODO
	Table* table = new Table();
	Composition* composition = new Composition( rules.numOfDecks );

	table->SetCards( composition );

	for ( int i = 0; i < rules.numOfPlayers; ++i )
	{
		Player* player = new Player();
		player->Join( *table );
		mpPlayers.push_back( player ); 
	}

	mpTables.push_back( table );
}*/

void GameManager::StartGame()
{
	Rules_t rules;

	rules.numOfDecks = 8;
	rules.numOfPlayers = 3;
	rules.canDouble = true;
	rules.canSurrender = false;

	Table* table = new Table( rules );


	Composition* composition = new Composition( rules.numOfDecks );
	composition->Shuffle();

	table->SetCards( composition );

	for ( int i = 0; i < rules.numOfPlayers; ++i )
	{
		Player* player = new Player();
		player->Join( *table );
		mpPlayers.push_back( player ); 
	}

	table->SetDealer( new Dealer() );

	table->SetEndOfComposition( 50 );

	mpTables.push_back( table );

	mpPlayers.at(0)->SetMoney( 10000 );
	mpPlayers.at(0)->Bet( 100 );


	table->Play();
}
