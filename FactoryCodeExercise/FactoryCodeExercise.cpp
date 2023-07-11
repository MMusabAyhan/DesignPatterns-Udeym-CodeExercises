#include <string>
#include <sstream>
#include <iostream>
//using namespace std;

struct Person
{
    int id;
    std::string name;

    friend std::ostream& operator<<(std::ostream& os, const Person& person)
    {
        os << person.id << ". Person name: "
            << person.name;

        return os;
    }
};

class PersonFactory
{
    int personId{ 0 };
public:
    Person create_person(const std::string& name)
    {
        return Person{personId++,name};
    }
};


int main() 
{
    PersonFactory PersonManufacturer;

    Person Person1 = PersonManufacturer.create_person("Musab");
    Person Person2 = PersonManufacturer.create_person("Ahmet");

    std::cout << Person1 << std::endl
              << Person2 << std::endl;
}
