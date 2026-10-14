#pragma once
#include "Card.h"
class BlackjackCard : public Card
{
public:
	BlackjackCard(const CardSuit& suit, const CardFace& face) :
		Card(suit,face)
	{
		//do NOT do what the base ctor does	
	}
};

