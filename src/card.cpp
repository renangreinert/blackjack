#include "card.h"

#include <cassert>

Card::Card()
{
}


Card::~Card()
{
}

std::vector< int > Card::GetNumericalValue() const
{
	std::vector< int > retval;

	switch ( mValue )
	{
	case ACE:
		retval.push_back( 1 );
		retval.push_back( 11 );
		break;

	case VAL_2:
	case VAL_3:
	case VAL_4:
	case VAL_5:
	case VAL_6:
	case VAL_7:
	case VAL_8:
	case VAL_9:
	case VAL_10:
		retval.push_back( (int)mValue ) ;
		break;

	case QUEEN:
	case KNIGHT:
	case KING:
		retval.push_back( 10 );
		break;

	default:
		assert( 0 );
		break;
	}

	return retval;
}