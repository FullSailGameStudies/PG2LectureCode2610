#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include "Player.h"
#include "Color.h"
#include "Pistol.h"


//overloads:
//	the parameters must be different
//	- either the number of params
//  - or the types of the params
int Add(int n1, int n2)
{
	return n1 + n2;
}
int Add(int n1, int n2, int n3)
{
	return n1 + n2 + n3;
}
float Add(float n1, float n2)
{
	return n1 + n2;
}

void Counter()
{
	static int i = 0;//only initializes it the first time
	std::cout << i << " ";
	i++;
}
int main(int argc, char* args[])
{
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	int sum = Add(5, 2);
	sum = Add(5, 3, 10);
	float sumF = Add(5.0f, 3.1f);

	Color clr;
	clr.red = 255;
	clr.green = clr.blue = 0;
	clr.alpha = 255;

	Pistol pewpew(100,200,10,15);
	Pistol p2(100, 200, 5, 15);
	pewpew.calcDamage();
	Pistol p3 = pewpew + p2;
	//Weapon wpn(10, 50);
	//wpn.showMe();
	p3.showMe();
	pewpew.showMe();
	p2.showMe();


	Player p1("BruceW", 100);//we call a ctor here
	//p1.SetGamerTag("BruceW");
	//p1.Level(100);
	std::cout << p1.GetGamerTag() << " Level: " << p1.Level() << "\n";


    std::string hello = "Hello Week 3!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Create Class",//classes + inheritance + override?
		"2. Part B-1: Inheritance, Polymorphism",//no pointers
		"3. Part C-1: Pointers",//pointers
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
			Day7::PartA_1();
			break;
		}
		case 2:
		{
			Day8::PartB_1();
			break;
		}
		case 3:
		{
			Day9::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());


	return 0;
}