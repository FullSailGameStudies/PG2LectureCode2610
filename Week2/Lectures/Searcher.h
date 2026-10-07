#pragma once
#include <vector>
#include "Light.h"

const int ITEM_NOT_FOUND = -1;

class Searcher
{
public:
	//
	// Part B-1
	//
	int LinearSearch(const std::vector<Light>& lights, int greenToFind) const;
};

