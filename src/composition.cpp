#include "composition.h"

#include "deckfactory.h"

#include <algorithm>

Composition::Composition( int numOfDecks )
{
	for ( int i = 0; i < numOfDecks; ++i )
	{
		constCardsVec_t aux = DeckFactory::CreateDeck();
		mCards.insert( mCards.end(), aux.begin(), aux.end() );
	}

	mCurrentCard = mCards.begin();
	mLastCard = mCards.end();
}



Composition::~Composition()
{
	DeckFactory::DestroyDeck( mCards );
}





int Composition::GetCard(const Card* card)
{
	int retval = 1;

	if ( mCurrentCard >= mCards.end() )
	{
		retval = -1;
		card = NULL;
	}
	else 
	{
		card = *mCurrentCard;

		if ( mCurrentCard <= mLastCard )
		{
			retval = 1;
		}
		else
		{
			retval = 0;
		}
	}
	
	return retval;
}


int Composition::GetNumOfCards()
{
	return mCards.size();
}

int Composition::GetNumOfCardsToTheEnd()
{
	return mLastCard - mCurrentCard;
}

void Composition::SetEnd(int position)
{
	mLastCard = mCards.begin() + position;
}


void Composition::Shuffle()
{
	std::random_shuffle ( mCards.begin(), mCards.end() );
}