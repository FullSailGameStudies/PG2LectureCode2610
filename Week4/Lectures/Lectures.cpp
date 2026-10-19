#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream> //fstream, ofstream, ifstream
#include <sstream> //stringstream
#include "Player.h"

int main(int argc, char* args[])
{
	//3 basic IO steps
	//1) open the file
	//	 - where is the file?
	//	 - what format is the data?
	//	 - are you writing or reading or both?
	//	 - did it work? is the file open?
	//2) writing/reading to the file
	//3) CLOSE the file

	//1) open the file
	std::string fileName = "2610.csv";
	std::string path = "C:/temp/2610/";
	std::string finalPath = path + fileName;
	std::ofstream outFile(finalPath);
	//it will create the file if it is not there
	//it will overwrite the file if it is there
	//it will NOT create the path.
	//if the path does not exists, it will fail to open the file
	//check if the file is open before proceeding
	char delimiter = '\n';
	char colDelim = '*';
	if (outFile.is_open())
	{
		//2) write to the file
		//<< - insertion operator
		outFile << "Batman is better than Superman.";
		outFile << delimiter << 5 << colDelim << 13 << delimiter << 14.5;
		outFile << delimiter << true;
	}
	else
	{
		std::cout << "Could not open " << finalPath << "\n";
	}
	//3) CLOSE the file
	//	- good practice: close the file ASAP
	outFile.close();

	std::ifstream inFile(finalPath);
	if (inFile.is_open())
	{
		//read the data
		//1) read a line from the file
		//use getline
		std::string line;
		//getline will read the stream until it reaches
		// a '\n' OR the end of the stream
		std::getline(inFile, line);
		std::cout << line << "\n";

		std::getline(inFile, line);
		//reading multiple pieces of data from the 1 line
		//use getline again!
		//string is NOT part of the same class hierarchy as ifstream
		//getline only can use istreams
		//convert the string to a stringstream!!
		std::stringstream lineStream(line);//5*13
		std::string data;
		//getline reads until it reaches the delim OR the end of the stream
		std::getline(lineStream, data, colDelim);//5
		int iData = std::stoi(data);
		std::cout << iData << "\n";

		std::getline(lineStream, data, colDelim);//13
		iData = std::stoi(data);
		std::cout << iData << "\n";

		std::getline(inFile, line);
		double dData = std::stod(line);
		std::cout << dData << "\n";

		//use try-catches to handle exceptions "gracefully"
		std::getline(inFile, line);
		try
		{
			//the code that "MIGHT" throw an exception
			//goes inside the 'try' block
			bool bData = std::stoi(line);// line == "1";// ? true : false;
			std::cout << bData << "\n";
		}
		//1 or more catch blocks to handle the possible exceptions
		catch (const std::exception& ex)
		{
			std::cout << "Failed converting boolean: " << line << "\n";
			std::cout << ex.what() << "\n";
		}
	}
	else
	{
		std::cout << "Could not open " << finalPath << "\n";
	}
	inFile.close();


    std::string hello = "Hello Week 4!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	Player p1;
	p1.MoveDown();
	p1.MoveDown();
	p1.MoveLeft();
	p1.MoveLeft();
	p1.MoveLeft();
	std::string saveFile = "player.csv";
	std::ofstream playerFile(saveFile);
	if (playerFile.is_open())
	{
		p1.SerializeCSV(playerFile, '\t');
	}
	else
	{
		std::cout << "Could not open " << saveFile << "\n";
	}
	playerFile.close();

	std::ifstream playerLoadFile(saveFile);
	if (playerLoadFile.is_open())
	{
		//read the line from the file
		std::string line;
		std::getline(playerLoadFile, line);

		//create a player object using the line
		Player loadedPlayer(line, '\t');
		int px, py;
		loadedPlayer.GetPosition(px, py);
		std::cout << px << "," << py << "\n";
	}
	else
	{
		std::cout << "Could not open " << saveFile << "\n";
	}
	playerLoadFile.close();

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Read CSV file",
		"2. Part A-2: Write CSV file",
		"3. Part B: Serialize/Deserialize objects",
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day10::PartA_1();
			break;
		}
		case 2:
		{
			Day10::PartA_2();
			break;
		}
		case 3:
		{
			Day11::PartB();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}