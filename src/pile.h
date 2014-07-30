#ifndef __PILE_H__
#define __PILE_H__

#include "bet.h"
#include "card.h"

#

typedef struct pile_t
{
	Bet bet;
	std::vector< const Card* > cards;
	bool stand; 
};

#endif

