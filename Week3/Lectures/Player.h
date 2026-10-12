#pragma once

//ONLY include headers that THIS file needs
#include <string>

class Player
{
//access modifiers: control what other code can see
public:  // ALL code can see it

	//constructors (ctors)
	//  special functions to initialize your object
	//	to make an instance of your class, you MUST call a ctor
	//  IF you don't create a ctor, the compiler gives you a default ctor
	//	a default ctor: a ctor w/out parameters
	//  IF you DO create a ctor, the compiler's ctor is NOT CREATED
	//  you can have as many of these as you need
	//  they can have any access modifier
	//	RULES:
	//		cannot have any return type at all (not even void)
	//		MUST be named the same as the class (casing included)
	//use the member initialization list to initialize your fields
	//it's the preferred way!
	Player(const std::string& tag) :
		//ALL fields are initialized HERE first
		gamerTag_(tag),
		level_(1)
	{
		//gamerTag_ = tag;
	}
	Player(const std::string& tag, int level) :
		//ALL fields are initialized HERE first
		gamerTag_(tag),
		level_(level)
	{
	}

	//getters (accessors)
	//  return type matches the type of the field
	//  usually no parameters
	//  const b/c they should not change the object
	//  can be defined in the header
	const std::string& GetGamerTag() const
	{
		return gamerTag_;
	}

	int Level() const { return level_; }

	//setter (mutator)
	//  return type is usually void
	//  has at least 1 parameter that matches the field type
	//  can't be const
	//  usually has some validation to verify the parameter
	void SetGamerTag(const std::string& tag)
	{
		//validation
		if (tag.size() > 0 && tag.size() < 32)
		{
			gamerTag_ = tag;
		}
	}

	void Level(int lvl)
	{
		if (lvl >= 0 && lvl <= 100)
		{
			level_ = lvl;
		}
	}



private: // ONLY this class can see it*. default

	//FIELDS:
	//	generally should be private (protect your data!)
	//  data members
	//  Naming conventions:  camelCasingNamingConvention
	//		for fields we usually add something else to make
	//		it stand out against other variables
	//		ex: m_iLevel, m_level, mLevel, _level, level_
	//			gamer_tag
	std::string gamerTag_;
	int level_;

protected: // this class and its descendents can see it

};

