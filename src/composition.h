#if !defined(_COMPOSITION_H_)
#define _COMPOSITION_H_

#include "card.h"
#include "cardsfuncs.h"

class Composition
{

public:
	Composition( int numOfDecks = 1 );
	virtual ~Composition();
	constCardsVec_t mCards;

	/////////////////////////////////////////////////////
	/// Take the top card from the deck/composition and return
	/// it in "card".
	/// \retval 1 - If success.
	/// \retval 0 - If the composition has not finished yet but we've already passed the "last card". 
	/// \retval -1 - If there are no more cards left. Will return NULL.
	/////////////////////////////////////////////////////
	int GetCard(const Card*& card);

	/////////////////////////////////////////////////////
	/// Returns the quantity of cards of this composition
	/////////////////////////////////////////////////////
	int GetNumOfCards();

	/////////////////////////////////////////////////////
	/// Returns the quantity of the cards to be drawn until
	/// the end of the composition
	/////////////////////////////////////////////////////
	int GetNumOfCardsToTheEnd();

	void SetEnd(int position);
	void Shuffle();

	constCardsVec_t::iterator mCurrentCard;	//!< Points to the current card being drawn.
	constCardsVec_t::iterator mLastCard;	//!< Will point to the last card of this composition. The card where the play will end to be shuffled again.
};
#endif




