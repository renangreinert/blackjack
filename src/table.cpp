#include "table.h"
#include "player.h"
#include "card.h"
#include "dealer.h"
#include "composition.h"

Table::Table()
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