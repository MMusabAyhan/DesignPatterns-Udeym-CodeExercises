#include "exercise.h"

int sum(const vector<ContainsIntegers*> items)
{
	int sum{0};
	for (auto&& item : items)
	{
		for (auto&& intFromList : item->IntList)
		{
			sum += intFromList;
		}
	}

	return sum;
}