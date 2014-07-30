#if !defined(_DECKFACTORY_H_)
#define _DECKFACTORY_H_

#include "card.h"

class DeckFactory
{

public:
	DeckFactory();
	virtual ~DeckFactory();

	static Card* CreateDeck();

};
#endif



