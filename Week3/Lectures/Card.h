#pragma once
#include "enums.h"
class Card
{
public:

	Card(const CardSuit& suit, const CardFace& face)
		: suit_(suit), face_(face)
	{}

	virtual int Value() const;
	void Print() const;

	CardSuit Suit() const { return suit_; }
	CardFace Face() const { return face_; }

	void Suit(CardSuit suit)
	{
		if (suit >= CardSuit::Hearts && suit <= CardSuit::Spades)
			suit_ = suit;
	}
	void Face(CardFace face)
	{
		if (face >= CardFace::A && face <= CardFace::King)
			face_ = face;
	}


protected:
	CardSuit suit_;
	CardFace face_;
};

