#include "table.h"
#include "player.h"
#include "card.h"
#include "dealer.h"
#include "composition.h"

Table::Table( const Rules_t& rules ): mRules( rules )
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
		if ( (*iter)->IsPlaying() )
		{
			while ( (*iter)->Play() );
		}
	}

	while ( mpDealer->Play() );
	return 0;
}


void Table::Restart()
{
}


int Table::AddPlayer( Player* player )
{
	if ( mpPlayers.size() < (unsigned int)mMaxPlayers )
	{
		mpPlayers.push_back( player );
	}
	return 1;
}

void Table::SetDealer( Dealer* dealer )
{ 
	mpDealer = dealer; 
	mpDealer->SetTable( this ); 
}

void Table::SetEndOfComposition( int end )
{
	mpComposition->SetEnd( end );
}


