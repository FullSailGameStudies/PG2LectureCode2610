#pragma once
#include <string>
#include <vector>
#include <enums.h>
class DayCode
{
public:
	static void ShowMenu(const std::string& title, const std::vector<std::string>& menuOptions);

	static std::string ToString(CardFace face);
	static std::string ToString(CardSuit suit);
};

