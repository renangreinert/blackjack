#if !defined(_DECKFACTORY_H_)
#define _DECKFACTORY_H_

#include "card.h"
#include "cardsfuncs.h"

class DeckFactory
{

public:
	static constCardsVec_t CreateDeck();
	static void DestroyDeck( constCardsVec_t& deck );

};
#endif



