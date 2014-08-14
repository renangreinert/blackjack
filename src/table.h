#if !defined(_TABLE_H_)
#define _TABLE_H_

#include < vector >

class Player;
class Dealer;
class Composition;
class Card;

enum ESoftRule
{
	SOFT_STAND,
	SOFT_HIT
};

struct Rules_t
{
	int numOfDecks;		//!< Number of decks
	int numOfPlayers;	//!< Number of players allowed per table
	bool canDouble;
	bool canSurrender;
	ESoftRule softRule;
	float jackpotPayment;
};

class Table
{
public:
	Table( const Rules_t& rules );
	virtual ~Table();

	const Card* GetCard();
	int Play();
	void Restart();

	int AddPlayer( Player* player );

	
	void SetMaxPlayers( int maxPlayers ) { mMaxPlayers = maxPlayers; }
	
	void SetCards( Composition* composition ){ mpComposition = composition; }

	std::vector< Player* > GetPlayers(){ return mpPlayers; }

	Dealer* GetDealer(){ return mpDealer; }

	void SetDealer( Dealer* dealer );

	void SetEndOfComposition( int end );

	Rules_t GetRules(){ return mRules; }

private:

	Composition*	mpComposition;
	Dealer*			mpDealer;
	int				mMaxPlayers;

	Rules_t			mRules;

	std::vector< Player* > mpPlayers;




};

#endif





