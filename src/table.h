#if !defined(_TABLE_H_)
#define _TABLE_H_

#include < vector >

class Player;
class Dealer;
class Composition;
class Card;

class Table
{
public:
	Table();
	virtual ~Table();

	const Card* GetCard();
	int Play();
	void Restart();

	int AddPlayer( Player* player );

	Dealer* GetDealer(){ return mpDealer; }

	void SetCards( Composition* composition ){ mpComposition = composition; }

	std::vector< Player* > GetPlayers(){ return mpPlayers; }

private:
	Composition* mpComposition;
	Dealer* mpDealer;
	std::vector< Player* > mpPlayers;

};

#endif





