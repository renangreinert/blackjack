#include "dealer.h"

#include "card.h"
#include "table.h"
#include "player.h"

#include <cstdlib>
#include <cassert>


Dealer::Dealer(): mpHiddenCard( NULL ), mpVisibleCard( NULL )
{
}

Dealer::~Dealer()
{
	mpVisibleCard = NULL;
	mpHiddenCard = NULL;
	mpTable = NULL;

	mpOtherCards.clear();
}

int Dealer::Play()
{
	return 0;
}

void Dealer::DealCards()
{
	assert( mpTable != NULL );

	std::vector< Player* > players = mpTable->GetPlayers();

	assert( players.size() > 0 );

	//deal the first card
	for ( std::vector< Player* >::iterator iter = players.begin(); 
		iter != players.end();
		++iter )
	{
		(*iter)->PushCard( mpTable->GetCard() );
	}
	mpHiddenCard = mpTable->GetCard();


	//deal second cards
	for ( std::vector< Player* >::iterator iter = players.begin(); 
		iter != players.end();
		++iter )
	{
		(*iter)->PushCard( mpTable->GetCard() );
	}
	mpVisibleCard = mpTable->GetCard();

}
