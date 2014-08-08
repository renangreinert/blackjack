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

class Table
{
public:
	Table( ESoftRule softRule = SOFT_STAND, float jackpotPayment = 2.0f );
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

	ESoftRule GetSoftRule(){ return mSoftRule; }

private:
	ESoftRule		mSoftRule;
	float			mJackpotPayment;
	Composition*	mpComposition;
	Dealer*			mpDealer;
	int				mMaxPlayers;

	std::vector< Player* > mpPlayers;


};

#endif





