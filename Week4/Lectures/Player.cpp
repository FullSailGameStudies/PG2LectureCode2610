#include "Player.h"
#include "Console.h"
#include <iomanip>
#include <sstream>

//
// Part B-1.2
//

//
// Part B-2.2
//

void Player::Info()
{
	Console::SetCursorPosition(0, 12);
	std::cout << "POSITION: " << std::setw(7) << std::right << worldX << "," << worldY;
}

void Player::SerializeCSV(std::ofstream& oFile, char delimiter) const
{
	oFile << worldX << delimiter << worldY;
}

void Player::DeserializeCSV(const std::string& csvData, char delimiter)
{
	std::stringstream csvStream(csvData);
	std::string data;

	std::getline(csvStream, data, delimiter);
	worldX = std::stoi(data);

	std::getline(csvStream, data, delimiter);
	worldY = std::stoi(data);
}
