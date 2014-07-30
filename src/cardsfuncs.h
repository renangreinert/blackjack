#ifndef __CARDS_FUNCS_H__
#define __CARDS_FUNCS_H__

#include "card.h"
#include <vector>

typedef std::vector< const Card* > constCardsVec_t;


namespace CardsFuncs
{

	//////////////////////////////////////////
	/// Analyse the pile and check if it can be splitted.
	//////////////////////////////////////////
	bool IsPair( constCardsVec_t& cards );

	//////////////////////////////////////////
	/// Analyse if the pile has an ace or not.
	//////////////////////////////////////////
	bool HasAce( constCardsVec_t& cards );
	
	//////////////////////////////////////////
	/// Get the sum of the cards.
	/// \param aceAsEleven - if true, consider "11" as 
	/// the ace's value
	//////////////////////////////////////////
	int Sum( constCardsVec_t& cards, bool aceAsEleven = false );
}

#endif

