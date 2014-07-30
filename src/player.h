
#if !defined(_PLAYER_H_)
#define _PLAYER_H_

#include <vector>
#include "bet.h"

class Card;
class Table;


class Player
{

public:
	Player();
	virtual ~Player();
	void Pay(int value);

	////////////////////////////////////////////////////////////
	/// Plays one step.
	/// \retval 1 - ok
	/// \retval 0 - Will not play anymore.
	////////////////////////////////////////////////////////////
	int Play();

	////////////////////////////////////////////////////////////
	/// To be called when the match finishes.
	////////////////////////////////////////////////////////////
	void Clear();

	////////////////////////////////////////////////////////////
	/// Sends one card to this player (initial draw)
	////////////////////////////////////////////////////////////
	void PushCard( const Card* card );

	////////////////////////////////////////////////////////////
	/// Place a bet. Decrements the player's money.
	/// \retval 1 - OK
	/// \retval 0 - doesn't have enough money to bet
	////////////////////////////////////////////////////////////
	int Bet( int value );

	int Join( Table& table );

	typedef struct pile_t
	{
		class Bet bet;
		std::vector< const Card* > cards;
		bool stand; 
	};

private:
	std::vector< pile_t > mPiles;
	int mMoney;
	Table* mpTable;	//!< Table where the player is playing

};

#endif 



