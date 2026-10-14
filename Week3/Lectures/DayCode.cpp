#include "DayCode.h"
#include <iostream>

void DayCode::ShowMenu(const std::string& title, const std::vector<std::string>& menuOptions)
{
	std::cout << "\n\n" << title << "\n";
	for (auto& option : menuOptions)
	{
		std::cout << option << "\n";
	}
	std::cout << "\nSelect an option: \n";
}

std::string DayCode::ToString(CardSuit suit)
{
	switch (suit)
	{
	case Hearts:
		return "Hearts";
		break;
	case Diamonds:
		return "Diamonds";
		break;
	case Clubs:
		return "Clubs";
		break;
	case Spades:
		return "Spades";
		break;
	default:
		break;
	}
	return "";
}

std::string DayCode::ToString(CardFace face)
{
	std::string f = "";
	switch (face)
	{
	case A:
		f = "A";
		break;
	case Jack:
		f = "J";
		break;
	case Queen:
		f = "Q";
		break;
	case King:
		f = "K";
		break;
	default:
		f = std::to_string(face);
		break;
	}
	return f;
}