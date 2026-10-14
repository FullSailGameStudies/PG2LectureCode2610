#include <iostream>
#include "Weapon.h"

Weapon::Weapon(int range, int damage) : mRange(range), mDamage(damage)
{
}

void Weapon::showMe() const
{
	std::cout << "Range: " << mRange << " Damage: " << mDamage << "\n";
}

int Weapon::calcDamage()
{
	return rand() % (mDamage+1);
}
