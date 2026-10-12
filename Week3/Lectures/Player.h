#pragma once

//ONLY include headers that THIS file needs
#include <string>

class Player
{
//access modifiers: control what other code can see
public:  // ALL code can see it

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

