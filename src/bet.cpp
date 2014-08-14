#include "bet.h"


Bet::Bet(): mValue(0)
{
}

Bet::~Bet()
{
}

Bet::Bet( int value ): mValue( value )
{
}

void Bet::Clear()
{
	mValue = 0;
}

void Bet::Double()
{
	mValue *= 2;
}

const int Bet::GetValue()
{
	return mValue;
}

void Bet::Set(int value)
{
	mValue = value;
}