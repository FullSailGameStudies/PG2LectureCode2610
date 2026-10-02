#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

//pass by reference:
//REASONS:
//	1) we need to update a variable in a different scope
//  2) we want to prevent a copy (for performance)
//		- general rule: if the type is a class, pass by reference

//default params must appear at the end of the param list
void Factor(double& valueToUpdate, double fac = 0)//pass by reference (ALIAS)
{
	if (fac == 0)
		fac = rand() % 100;
	valueToUpdate *=(fac);
}
void Print(const std::vector<int>& nummies)//prevents a copy
{
	//range-based loop (foreach)
	//for (auto& numm : nummies)
	//{
	//	std::cout << numm << '\n';
	//}
	for (int i = 0; i < nummies.size(); i++)
	{

	}
	//iterator loop
	for (auto it = nummies.begin();it != nummies.end();it++)
	{
		std::cout << *it << " ";
	}
}

const float PI = 3.1415F;

int main(int argc, char* args[])
{
	double dVal = 10;
	Factor(dVal, 3);//fac = 3
	Factor(dVal, 5);//fac = 5
	Factor(dVal);
	std::vector<int> nummies{ 1,2,2,2,3,4,4,5,6,6 };
	std::vector<int>::iterator nummyIter = nummies.begin();
	std::cout << *nummyIter << "\n";
	//iterator + index will give an iterator to the item at index
	//erase all the 2s
	std::cout << "\nBEFORE:\n";
	Print(nummies);

	for (int i = 0; i < nummies.size();)
	{
		if (nummies[i] == 2) 
			nummies.erase(nummies.begin() + i);
		else 
			i++;
	}
	//reverse for loop
	for (int i = nummies.size() - 1; i >= 0; i--)
	{
		if (nummies[i] == 2)
			nummies.erase(nummies.begin() + i);
	}
	for (auto it = nummies.begin(); it != nummies.end();)
	{
		if (2 == *it)
		{
			it = nummies.erase(it);
		}
		else it++;
	}
	std::cout << "\nAFTER:\n";
	Print(nummies);

	double value = 12;
	Factor(value);
	std::cout << value << "\n";

	Day2 day2;

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1.0: Calling static methods",
		"2. Part A-1.1: calling non-static methods",
		"3. Part A-1.2: calling non-static methods",
		"4. Part A-1.3: calling non-static methods",
		"5. Part A-1.4: Return Values",
		"6. Part A-1.5: Passing arguments",
		"7. Part A-2: Creating methods\n",
		"8. Part B-1: Pass by reference",
		"9. Part B-2: Const",
		"10. Part B-3: Erasing in a loop\n",
		"11. Part C-1: Default Parameters",
		"12. Part C-2: Copying Vectors\n",
		"13. Exit" };

	std::vector<int> nummbers{ 1,2,3,4,5 };
	int numberOfOptions = menuOptions.size();
	int nums            = nummbers.size();

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1.0: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//
			Console::Write("DC is better than Marvel?!");
			Console::WriteLine(" CORRECT!", ConsoleColor::Green);
			break;
		}
		case 2:
		{
			Day1::PartA_1_1();
			break;
		}
		case 3:
		{
			Day1::PartA_1_2();
			break;
		}
		case 4:
		{
			Day1::PartA_1_3();
			break;
		}
		case 5:
		{
			//
			// part A-1.4: Getting return values
			//	Ask the user to enter their name. Print the name.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetString.
			//	Store the result in a string variable.
			//	Print the name that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetString is declared.
			//
			std::string name = Input::GetString("What is your name? ");
			std::cout << "Your name is " << name << "? I like that name.\n";
			break;
		}
		case 6:
		{
			//
			// part A-1.5: passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			int age = Input::GetInteger("How old are you? ", 0, 120);
			std::cout << "You are " << age << " years old.\n";
			break;
		}
		case 7:
		{
			Day1::PartA_2();
			break;
		}
		case 8:
		{
			day2.PartB();
			break;
		}
		case 9:
		{
			day2.PartB(2);
			break;
		}
		case 10:
		{
			day2.PartB(3);
			break;
		}
		case 11:
		{
			Day3::PartC_1();
			break;
		}
		case 12:
		{
			Day3::PartC_2();
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}

