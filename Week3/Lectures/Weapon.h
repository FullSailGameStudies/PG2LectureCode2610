#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);
	virtual ~Weapon() = default;

	//OVERRIDING:
	// 1) mark the base method as `virtual`
	virtual void showMe() const;
	virtual int calcDamage();// = 0;//make it a pure virtual. now Weapon is an abstract base class

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

