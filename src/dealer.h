#if !defined(DEALER_H_)
#define DEALER_H_

#include <vector>

class Card;
class Table;

class Dealer
{

public:
	Dealer();
	virtual ~Dealer();

	const Card* GetVisibleCard() { return mpVisibleCard; }
	int Play();

	/////////////////////////////////////////////////////////
	/// Deals the two initial cards to all the players in the
	/// table and to the dealer
	/////////////////////////////////////////////////////////
	void DealCards();

	void SetTable( Table* table ){ mpTable = table; }

private:
	const Card* mpVisibleCard;
	const Card* mpHiddenCard;

	std::vector< const Card* > mpOtherCards;

	Table* mpTable;

};
#endif

