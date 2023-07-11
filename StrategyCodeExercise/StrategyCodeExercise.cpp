#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override {
        return b * b - 4 * a * c;
    }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override {
        double result = b * b - 4 * a * c;
        return result >= 0 ? result : numeric_limits<double>::quiet_NaN();
    }
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy& strategy) : strategy(strategy) {}

    tuple<complex<double>, complex<double>> solve(double a, double b, double c)
    {
        complex<double> disc{ strategy.calculate_discriminant(a,b,c), 0 };
        auto root_disc = sqrt(disc);
        return {
            (-b + root_disc) / (2 * a),
            (-b - root_disc) / (2 * a) };
    };
};

int main() 
{
	OrdinaryDiscriminantStrategy ODS;
	RealDiscriminantStrategy RDS;

	QuadraticEquationSolver QES1(ODS);
	QuadraticEquationSolver QES2(RDS);

	cout << get<0>(QES1.solve(1, 10, 16)) << get<1>(QES1.solve(1, 10, 16)) << endl;
    cout << get<0>(QES2.solve(1, 10, 16)) << get<1>(QES2.solve(1, 10, 16)) << endl;


}
