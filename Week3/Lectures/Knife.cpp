#include "Knife.h"
#include <iostream>
int Knife::calcDamage()
{
	return Weapon::calcDamage();
}

void Knife::showMe() const
{
	std::cout << "Knife: Is Serrated? " << (mSerrated ? "yes" : "no");//ternary
	std::cout << "\t";//\t means tab   \n means newline
	Weapon::showMe();
}

