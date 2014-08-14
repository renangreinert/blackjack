
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

	////////////////////////////////////////////////////////////
	/// Returns true is the player is playing this round or not
	/// (in other words, if he has placed a bet)
	////////////////////////////////////////////////////////////
	bool IsPlaying();


	Table* GetTable(){ return mpTable; }

	int Join( Table& table );


	void SetMoney( int money ){ mMoney = money; }

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



	//Defines the prototype of the function that will do an action with a player's pile.
	typedef void (*playfunc_t)( Player&, Player::pile_t& );

	static playfunc_t matrixHardTotal[21][10];
	static playfunc_t matrixSoftTotal[10][10];
	static playfunc_t matrixPairs[11][10];

	//static functions for playing the cards:
	static void PlayHit( Player& pPlayer, Player::pile_t& pPile );
	static void PlayStand( Player& player, Player::pile_t& pPile );
	static void PlaySplit( Player& player, Player::pile_t& pPile );	
	static void PlayDbl( Player& player, Player::pile_t& pPile );	
	static void PlayDblHit( Player& player, Player::pile_t& pPile );
	static void PlayDblStand( Player& player, Player::pile_t& pPile );	
	static void PlaySurrender( Player& player, Player::pile_t& pPile );

	
};

#endif 



