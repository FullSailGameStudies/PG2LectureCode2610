#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>
#include <map>
#include <iomanip> //lets us add some formatting commands to cout

void SomeFunc(int someData)
{
	//ALL recursive functions REQUIRE an exit condition (base case)
	//exit the function w/out calling the function again
	if (someData >= 1000) return;
	
	std::cout << someData << " ";
	//recursive case (when a function calls itself)
	SomeFunc(someData + 1);
	
	Console::Write(someData, (ConsoleColor)(rand() % ConsoleColor::White));
}

int main(int argc, char* args[])
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
	}
	//SomeFunc(10);
	srand(static_cast<unsigned int>(time(NULL)));

	std::string hello = "Hello Week 2!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	//maps:
	// keys must be unique
	// 
	//storing menu items and their prices
	//menu items are string (the name)
	//prices are floats
	std::map<std::string, float> menu;

	//2 ways to add data to a map
	// 1) "easy" way
	//		map[key] = value;
	menu["lemonade"] = 3.25f;
	menu["chocolate chip cookies"] = 3.50f;
	menu["sushi"] = 11.99f;
	menu["sushi"] = 9.99f;//overwrites any existing value

	// 2) "not-as-easy" way
	//	  map.insert(key-value-pair);
	std::pair<std::string, float> itemToInsert = 
		std::make_pair("pepperoni pizza", 19.99f);
	menu.insert(itemToInsert);
	//parts of a pair object:
	//  first
	//  second
	itemToInsert.second = 14.99f;
	std::pair<std::map<std::string,float>::iterator,bool> menuItemInserted = menu.insert(itemToInsert);//does NOT overwrite
	if (menuItemInserted.second == false)
	{
		std::cout << itemToInsert.first << " is already on the menu. Do you want to update the price?\n";
		auto& keyValuePair = *(menuItemInserted.first);
	}

	std::pair<std::string, float> chips =
		std::make_pair("chips", 1.99f);
	menu.insert(chips);


	//accessing data in a map
	//  map[key] to access the value associated with the key
	std::string itemToAccess = "pepperoni pizza";
	//float priceOfItem = menu[itemToAccess];
	//std::cout << itemToAccess << " costs " << priceOfItem << "\n";

	//use map.find(key) to see if the key-value pair is in the map
	std::map<std::string,float>::iterator itemFoundIterator = menu.find(itemToAccess);

	//if the key is NOT found, the iterator equals the end()
	if (itemFoundIterator == menu.end()) //not found
	{
		std::cout << itemToAccess << " is not on the menu. Try McDonald's\n";
	}
	else
	{
		//the `->` operator goes to the object the iterator points to
		std::cout << itemToAccess << " costs " << itemFoundIterator->second << "\n";
	}

	std::cout << "\n\nPG2 Cafe\n";
	for (auto iter = menu.begin(); iter != menu.end(); iter++)
	{
		//iterator points to a key-value pair object (first,second)
		//first is the key (name), second is the value (price)
		std::cout << std::setw(7) << std::right << iter->second << " " ;
		std::cout << std::left << iter->first << "\n";
	}
	std::cout << "\n";

	std::cout << "\n\nPG2 Cafe\n";
	for (auto& kvp : menu)
	{
		std::cout << std::setw(7) << std::right << kvp.second << " ";
		std::cout << std::left << kvp.first << "\n";
	}

	//use structured bindings to make it more readable
	std::cout << "\n\nPG2 Cafe\n";
	for (auto& [itemName,itemPrice] : menu)
	{
		std::cout << std::setw(7) << std::right << itemPrice << " ";
		std::cout << std::left << itemName << "\n";
	}



	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Recursion Example\n",
		"2. Part A-1.1: Recursion (Bats)",
		"3. Part A-1.2: Recursion (Reverse Word)",
		"4. Part A-1.3: Recursion (Reverse words in a sentence)\n",
		"5. Part A-2: Sorting\n",
		"6. Part B-1: Linear Search\n",
		"7. Part B-2: Maps",
		"8. Part B-3: Find in Maps",
		"9. Part C-1: Erase from Maps",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day4::RecursionExample();
			break;
		}
		case 2:
		{
			Day4::PartA_1_1();
			break;
		}
		case 3:
		{
			Day4::PartA_1_2();
			break;
		}
		case 4:
		{
			Day4::PartA_1_3();
			break;
		}
		case 5:
		{
			Day4::PartA_2();
			break;
		}
		case 6:
		{
			Day5::PartB_1();
			break;
		}
		case 7:
		{
			Day5::PartB_2(1);
			break;
		}
		case 8:
		{
			Day5::PartB_2(2);
			break;
		}
		case 9:
		{
			Day6::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}