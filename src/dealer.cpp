#include "dealer.h"

#include "card.h"
#include "table.h"
#include "player.h"
#include "cardsfuncs.h"

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
	int retval = 0;

	constCardsVec_t vectCards = mpOtherCards;
	vectCards.push_back( mpVisibleCard );
	vectCards.push_back( mpHiddenCard );

	if ( CardsFuncs::Sum( vectCards, true ) < 17 || ( CardsFuncs::Sum( vectCards, false ) && mpTable->GetRules().softRule == SOFT_HIT ) )
	{
		retval = 1;
		mpOtherCards.push_back( mpTable->GetCard() );
	}

	return retval;
}

void Dealer::DealCards()
{
	assert( mpTable != NULL );

	std::vector< Player* > players = mpTable->GetPlayers();

	assert( players.size() > 0 );

	mpOtherCards.clear();

	//deal the first card
	for ( std::vector< Player* >::iterator iter = players.begin(); 
		iter != players.end();
		++iter )
	{
		if ( (*iter)->IsPlaying() )
		{
			(*iter)->PushCard( mpTable->GetCard() );
		}
	}
	mpHiddenCard = mpTable->GetCard();


	//deal second cards
	for ( std::vector< Player* >::iterator iter = players.begin(); 
		iter != players.end();
		++iter )
	{
		if ( (*iter)->IsPlaying() )
		{
			(*iter)->PushCard( mpTable->GetCard() );
		}
	}
	mpVisibleCard = mpTable->GetCard();

}
