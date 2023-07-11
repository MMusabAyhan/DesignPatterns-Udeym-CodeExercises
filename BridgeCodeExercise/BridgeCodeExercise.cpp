#include <string>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Renderer
{
    virtual string what_to_render_as() const = 0;
};

struct VectorRenderer : Renderer
{
    string what_to_render_as() const override
    {
        return "lines";
    }
};

struct RasterRenderer : Renderer
{
    string what_to_render_as() const override
    {
        return "pixels";
    }
};

struct Shape
{
    const Renderer& ShapeRenderer;
    string Name;

    Shape(const Renderer& R) : ShapeRenderer(R) {}

    string str() const
    {
        ostringstream oss;
        oss << "Drawing " << Name << " as "
            << ShapeRenderer.what_to_render_as();
        return oss.str();
    };
};


struct Triangle : Shape
{
    Triangle(const Renderer& R) : Shape(R)
    {
        Name = "Triangle";
    }
};

struct Square : Shape
{
    Square(const Renderer& R) : Shape(R)
    {
        Name = "Square";
    }
};

int main() 
{
    VectorRenderer Vr1;

    std::cout << Square(Vr1).str() << std::endl;

    RasterRenderer Vr2;

    std::cout << Square(Vr2).str() << std::endl;
}

// imagine e.g. VectorTriangle/RasterTriangle etc. here