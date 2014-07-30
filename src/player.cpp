#include "player.h"
#include "bet.h"
#include "card.h"
#include "table.h"
#include "dealer.h"
#include "cardsfuncs.h"

#include <cassert>


//Defines the prototype of the function that will do an action with a player's pile.
typedef void (*playfunc_t)( Player&, Player::pile_t& );

static void PlayHit( Player& pPlayer, Player::pile_t& pPile )
{
}

static void PlayStand( Player& player, Player::pile_t& pPile )
{
}

static void PlaySplit( Player& player, Player::pile_t& pPile )
{
}

static void PlayDbl( Player& player, Player::pile_t& pPile )
{
}

static void PlayDblHit( Player& player, Player::pile_t& pPile )
{
}

static void PlayDblStand( Player& player, Player::pile_t& pPile )
{
}

static void PlaySurrender( Player& player, Player::pile_t& pPile )
{
}

//Decision matrix

//matrix for hard totals (no pair, no Aces)
playfunc_t matrixHardTotal[21][10] = 
{
	//Dealer card:
	// 2				3				4				5				6				7				8				9				10				A			/* sum of player's cards */
	{ NULL,				NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL },				//   0
	{ NULL,				NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL },				//   1
	{ NULL,				NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL },				//   2
	{ NULL,				NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL },				//   3
	{ NULL,				NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL },				//   4
	{ &PlayHit,			&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   5
	{ &PlayHit,			&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   6
	{ &PlayHit,			&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   7
	{ &PlayHit,			&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   8
	{ &PlayHit,			&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   9
	{ &PlayDblHit,		&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayHit,		&PlayHit },			//   10
	{ &PlayDblHit,		&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayHit },			//   11
	{ &PlayHit,			&PlayHit,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   12
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   13
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   14
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayHit,		&PlayHit,		&PlayHit,		&PlaySurrender,	&PlayHit },			//   15
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayHit,		&PlayHit,		&PlaySurrender,	&PlaySurrender,	&PlaySurrender },	//   16
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand },		//   17
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand },		//   18
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand },		//   19
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand },		//   20
};


//matrix for soft totals (one Ace)
playfunc_t matrixSoftTotal[10][10] = 
{
	//Dealer card:
	// 2				3				4				5				6				7				8				9				10				A				/* player's card (other than Ace) */
	{ NULL,				NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL },					//   0
	{ &PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit },			//   1
	{ &PlayHit,			&PlayHit,		&PlayHit,		&PlayDblHit,	&PlayDblHit,	&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },				//   2
	{ &PlayHit,			&PlayHit,		&PlayHit,		&PlayDblHit,	&PlayDblHit,	&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },				//   3
	{ &PlayHit,			&PlayHit,		&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },				//   4
	{ &PlayHit,			&PlayHit,		&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },				//   5
	{ &PlayHit,			&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },				//   6
	{ &PlayStand,		&PlayDblStand,	&PlayDblStand,	&PlayDblStand,	&PlayDblStand,	&PlayStand,		&PlayStand,		&PlayHit,		&PlayHit,		&PlayHit },				//   7
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand },			//   8
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand },			//   9
};


//matrix for pairs
playfunc_t matrixPairs[11][10] = 
{
	//Dealer card:
	// 2				3				4				5				6				7				8				9				10				A				/* player's cards */
	{ NULL,				NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL,			NULL },				//   0 
	{ &PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit },		//   1 (Ace)
	{ &PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   2
	{ &PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   3
	{ &PlayHit,			&PlayHit,		&PlayHit,		&PlaySplit,		&PlaySplit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   4
	{ &PlayDblHit,		&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayDblHit,	&PlayHit,		&PlayHit },			//   5
	{ &PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   6
	{ &PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlayHit,		&PlayHit,		&PlayHit,		&PlayHit },			//   7
	{ &PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit },		//   8
	{ &PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlaySplit,		&PlayStand,		&PlaySplit,		&PlaySplit,		&PlayStand,		&PlayStand },		//   9
	{ &PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand,		&PlayStand },		//   10
};

Player::Player(): mMoney(0)
{
}

Player::~Player()
{
}

void Player::Clear()
{
	mPiles.clear();
}

void Player::Pay(int value)
{
	assert( value >= 0 );
	mMoney += value;
}

int Player::Play()
{
	int retval = 0;
	const Card* dealerVisibleCard = mpTable->GetDealer()->GetVisibleCard();

	for ( std::vector< pile_t >::iterator iter = mPiles.begin(); iter != mPiles.end(); ++iter )
	{
		if ( iter->stand == false ) 
		{
			retval = 1;
			if ( CardsFuncs::IsPair( iter->cards ) )
			{
				(matrixPairs[ iter->cards.at( 0 )->GetNumericalValue().at( 0 ) ][ dealerVisibleCard->GetNumericalValue().at( 0 ) ])( *this, *iter );
			}

			else if ( CardsFuncs::HasAce( iter->cards ) )
			{
				//sum or our cards minus the Ace.
				(matrixSoftTotal[ CardsFuncs::Sum( iter->cards ) - 1 ][ dealerVisibleCard->GetNumericalValue().at( 0 ) ])( *this, *iter );
			}
			else
			{
				(matrixHardTotal[ CardsFuncs::Sum( iter->cards ) ][ dealerVisibleCard->GetNumericalValue().at( 0 ) ])( *this, *iter );
			}
			break;
		}
	}
	return retval;
}

void Player::PushCard( const Card* card )
{
	assert( mPiles.size() > 0 );

	for ( std::vector< pile_t >::iterator iter = mPiles.begin(); iter != mPiles.end(); ++iter )
	{
		if ( iter->stand == false ) 
		{
			iter->cards.push_back( card );
			break;
		}
	}
}

int Player::Bet( int value )
{
	int retval = 0;

	assert( value > 0 );

	if ( value <= mMoney )
	{
		mMoney -= value;

		//create a pile with this bet
		pile_t pile = {};

		pile.bet.Set( value );

		pile.stand = false;

		mPiles.push_back( pile );

		retval = 1;
	}

	return retval;
}

int Player::Join( Table& table )
{
	int retval = 0;
	if ( table.AddPlayer( this ) )
	{
		mpTable = &table;
		retval = 1;
	}

	return retval;
}