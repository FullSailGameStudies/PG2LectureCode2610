#include "Pistol.h"
#include <iostream>

void Pistol::showMe() const
{
	//2 kinds of overrides:
	//  1) FULL override (totally new behavior)
	//		- do NOT call the base function
	//  2) EXTENSION override (add-on behavior)
	//		- call the base function too
	std::cout << "Pistol: " << mNumRounds << "/" << mMagCapacity;
	std::cout << "\t";//\t means tab   \n means newline
	Weapon::showMe();
}

int Pistol::calcDamage()
{
	return Weapon::calcDamage();
}
