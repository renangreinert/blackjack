#include "table.h"
#include "player.h"
#include "card.h"
#include "dealer.h"

Table::Table()
{
}



Table::~Table()
{
}





const Card* Table::GetCard()
{
	return  NULL;
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
	return 1;
}