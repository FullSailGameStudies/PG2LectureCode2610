#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:
	Knife(int range, int damage, bool serrated) :
		Weapon(range, damage),
		mSerrated(serrated)
	{

	}
	bool Serrated() const { return mSerrated; }
	void Serrated(bool serrated)
	{
		mSerrated = serrated;
	}

	int calcDamage() override;
	void showMe() const override;
private:
	bool mSerrated;
};

