#include <iostream>


struct Point
{
	int x{ 0 }, y{ 0 };

	Point() {}

	Point(const int x, const int y) : x{ x }, y{ y } {}
};

struct Line
{
	Point* start, * end;

	Line(Point* const start, Point* const end)
		: start(start), end(end)
	{
	}

	~Line()
	{
		delete start;
		delete end;
	}

	Line deep_copy() const
	{
		Point* point1 = new Point(start->x, start->y);
		Point* point2 = new Point(end->x, end->y);

		return Line(point1, point2);
	}
};

int main()
{
	Line myPrototypeLine = Line(new Point(1, 1), new Point(2, 2));
	Line myDeepCopyLine = myPrototypeLine.deep_copy();

	std::cout << "Original Line Point addresses | Point 1: " << myPrototypeLine.start
		      << " Point 2: " << myPrototypeLine.end << std::endl
		      << "Deep Copied Line Point addresses | Point 1: " << myDeepCopyLine.start
		      << " Point 2: " << myDeepCopyLine.end << std::endl;


	return 0;
}