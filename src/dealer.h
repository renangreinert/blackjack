#if !defined(DEALER_H_)
#define DEALER_H_

#include "card.h"

class Dealer
{

public:
	Dealer();
	virtual ~Dealer();
	Card *m_Card;

	const Card* GetVisibleCard();
	int Play();

};
#endif




