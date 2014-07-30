#if !defined(_COMPOSITION_H_)
#define _COMPOSITION_H_

#include "card.h"

class Composition
{

public:
	Composition();
	virtual ~Composition();
	Card *m_Card;

	int GetCard(const Card card);
	int GetNumOfCards();
	void SetEnd(int position);
	void Shuffle();

};
#endif




