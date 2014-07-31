#include "deckfactory.h"

#include <cstdlib>






constCardsVec_t DeckFactory::CreateDeck()
{
	constCardsVec_t retval;

	for ( int vals = 0; vals < TOTAL_VALUES; ++vals )
	{
		for ( int suit = 0; suit < TOTAL_SUITS; ++ suit )
		{
			retval.push_back( new Card((EVALUES)vals, (ESUIT)suit) );
		}
	}

	return retval;
}


void DeckFactory::DestroyDeck( constCardsVec_t& deck )
{
	for ( constCardsVec_t::iterator iter = deck.begin(); iter < deck.end(); ++iter )
	{
		delete *iter;
		*iter = NULL;
	}
}