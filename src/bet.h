
#if !defined(_BET_H_)
#define _BET_H_

class Bet
{

public:
	Bet();
	Bet( int value );
	virtual ~Bet();

	void Clear();
	void Double();
	const int GetValue();
	void Set(int value);

private:
	int mValue;

};
#endif



