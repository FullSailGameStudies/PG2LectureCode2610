#include "Searcher.h"

//
// Part B-1
//

int Searcher::LinearSearch(const std::vector<Light>& lights, int greenToFind) const
{
	for (int i = 0; i < lights.size(); i++)
	{
		if (greenToFind == lights[i].green)
		{
			return i;
		}
	}
    return ITEM_NOT_FOUND;
}
