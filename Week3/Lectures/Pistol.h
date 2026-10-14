#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:

	Pistol(int range, int damage, int numRounds, int magCapacity) :
		//member initialization list (base ctor calls & field inits)
		Weapon(range,damage),//call with arguments
		mNumRounds(numRounds), 
		mMagCapacity(magCapacity)
	{
	
	}


	int NumRounds() const { return mNumRounds; }
	int MagCapacity() const { return mMagCapacity; }

	void NumRounds(int rounds)
	{
		if (rounds >= 0 && rounds <= mMagCapacity)
			mNumRounds = rounds;
	}
	void MagCapacity(int cap)
	{
		if (cap > 0 && cap <= 15 && cap < mNumRounds)
			mMagCapacity = cap;
	}

private:
	int mNumRounds, mMagCapacity;
};

