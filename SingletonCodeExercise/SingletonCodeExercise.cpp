#include <functional>
#include <iostream>
using namespace std;

struct Car
{
    int WheelNumber;
    int Model;

    Car() : WheelNumber(4), Model(2010) {}
};
class CarFactory 
{  
public:
    CarFactory (){}
    
    static Car* GetSingleton()
    {
        static Car SingletonCar;
        return &SingletonCar;
    }


};

struct SingletonTester
{
    template <typename T>
    bool is_singleton(function<T* ()> factory)
    {
        T* SingletonInstance1 = factory();
        T* SingletonInstance2 = factory();
       
        if (SingletonInstance1 == SingletonInstance2)
        {
            return true;
        }

        return false;
    }
};

int main() 
{

    SingletonTester St;

    // Possible ways to Solution

    function<Car* ()> factory = CarFactory::GetSingleton;
    //cout << St.is_singleton(factory);

    cout << St.is_singleton<Car>(
            [](){
                   return CarFactory::GetSingleton();
                }
            );
          


    

}