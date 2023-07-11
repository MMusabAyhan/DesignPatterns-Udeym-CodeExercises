#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ContainsIntegers
{
    vector<int> IntList;
};

struct SingleValue : ContainsIntegers
{
  int value{ 0 };

  SingleValue() = default;

  explicit SingleValue(const int value)
    : value{value}
  {
      IntList.push_back(value);
  }   
};

struct ManyValues : ContainsIntegers
{
  void add(const int value)
  {
      IntList.push_back(value);
  }
};

int sum(const vector<ContainsIntegers*> items);