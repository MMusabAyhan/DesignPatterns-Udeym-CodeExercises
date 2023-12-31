#include <iostream>
struct Square
{
    int side{ 0 };


    explicit Square(const int side)
        : side(side)
    {
    }
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle
{
    SquareToRectangleAdapter(const Square& square)
        : square(square) {}

    int width() const override
    {
        return square.side;
    }

    int height() const override
    {
        return square.side;
    }

    const Square& square;
};

int main() 
{
  
    Square s(5);


    SquareToRectangleAdapter STRA(s);

    std::cout << STRA.area() << " " << STRA.width() << " " << STRA.height() << std::endl;



}