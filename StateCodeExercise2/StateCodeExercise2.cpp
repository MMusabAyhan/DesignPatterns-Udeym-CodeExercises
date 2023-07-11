#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CombinationLock
{
	vector<int> combination;
public:
	std::string status;

	CombinationLock(const vector<int>& combination) : combination(combination) {

		status = "LOCKED";
	}

	void enter_digit(int digit)
	{
		if (status == "LOCKED" || status == "ERROR")
		{
			status = to_string(digit);
		}

		else
		{
			status += to_string(digit);

			if (status.size() == 3)
			{
				bool result = checkCombination();
				status = (result) ? "OPEN" : "ERROR";
			}
		}

	}

	bool checkCombination()
	{
		std::string combinationStr = "";

		for (size_t i = 0; i < combination.size(); i++)
		{
			combinationStr += to_string(combination[i]);
		}

		return combinationStr == status;
	}

};

int main()
{
	CombinationLock cl({ 1,2,3 });

	cl.enter_digit(1);

	std::cout << cl.status << std::endl;

	cl.enter_digit(2);

	std::cout << cl.status << std::endl;

	cl.enter_digit(3);

	std::cout << cl.status << std::endl;
}