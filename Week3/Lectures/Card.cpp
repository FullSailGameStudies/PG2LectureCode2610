#include "Card.h"
#include <iostream>

int Card::Value() const
{
	return face_;
}

void Card::Print() const
{
	switch (face_)
	{
	case A:
		std::cout << "A ";
		break;
	case Jack:
		std::cout << "J ";
		break;
	case Queen:
		std::cout << "Q ";
		break;
	case King:
		std::cout << "K ";
		break;
	default:
		std::cout << face_ << " ";
		break;
	}
	switch (suit_)
	{
	case Hearts:
		std::cout << "Hearts";
		break;
	case Diamonds:
		std::cout << "Diamonds";
		break;
	case Clubs:
		std::cout << "Clubs";
		break;
	case Spades:
		std::cout << "Spades";
		break;
	default:
		break;
	}
	std::cout << "\n";
}
