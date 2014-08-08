#include "table.h"
#include "player.h"
#include "card.h"
#include "dealer.h"
#include "composition.h"

Table::Table( ESoftRule softRule, float jackpotPayment ): mSoftRule( softRule ), mJackpotPayment( jackpotPayment )
{
}

Table::~Table()
{
	delete mpComposition;
	mpComposition = NULL;
}


const Card* Table::GetCard()
{
	int ret = 0;
	const Card* card = NULL;

	ret = mpComposition->GetCard( card );

	//TODO - what to do in the case of an error?
	return  card;
}


/**
 * Returns 0 if can't play
 */
int Table::Play()
{
	mpDealer->DealCards();

	for ( std::vector< Player* >::iterator iter = mpPlayers.begin();
		iter != mpPlayers.end();
		++iter )
	{
		while ( (*iter)->Play() );
	}

	while ( mpDealer->Play() );
	return 0;
}


void Table::Restart()
{
}


int Table::AddPlayer( Player* player )
{
	mpPlayers.push_back( player );
	player->SetTable( this );
	return 1;
}