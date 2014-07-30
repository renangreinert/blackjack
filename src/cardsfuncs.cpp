#include "cardsfuncs.h"

bool CardsFuncs::IsPair( constCardsVec_t& cards )
{
	bool retval = false;

	if ( 
		( cards.size() == 2 ) && 
		( cards.at( 0 )->GetNumericalValue().at( 0 ) == cards.at( 1 )->GetNumericalValue().at( 0 ) ) 
		)
	{
		retval = true;
	}

	return retval;
}

bool CardsFuncs::HasAce( constCardsVec_t& cards )
{
	bool retval = false;

	for ( std::vector< const Card* >::const_iterator iter = cards.begin(); iter != cards.end(); ++iter )
	{
		if ( (*iter)->mValue == ACE )
		{
			retval = true;
			break;
		}
	}

	return retval;
}


int CardsFuncs::Sum( constCardsVec_t& cards, bool aceAsEleven )
{
	int ret = 0;

	for ( std::vector< const Card* >::const_iterator iter = cards.begin(); iter != cards.end(); ++iter )
	{
		if ( aceAsEleven && (*iter)->mValue == ACE )
		{
			ret += (*iter)->GetNumericalValue().at(1);
		}
		else
		{
			ret += (*iter)->GetNumericalValue().at(0);
		}
	}

	return ret;
}

