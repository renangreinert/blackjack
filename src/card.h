

#if !defined(_CARD_H_)
#define _CARD_H_

#include "ESUIT.h"
#include "EVALUES.h"

#include < vector >

class Card
{

public:
	Card();
	virtual ~Card();
	ESUIT mSuit;
	EVALUES mValue;

	std::vector< int > GetNumericalValue() const;

};
#endif



