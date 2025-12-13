#include <iostream>
#include "Point.hpp"

static Fixed cross(const Point& A, const Point& B, const Point& C)
{
	Fixed ABx = (B.getX() - A.getX());
	Fixed ABy = (B.getY() - A.getY());
	Fixed ACx = (C.getX() - A.getX());
	Fixed ACy = (C.getY() - A.getY());

	return (ABx * ACy - ABy * ACx);
}

bool bsp(const Point A, const Point B, const Point C, const Point point)
{
	Fixed cAB = cross(point, A, B);
	Fixed cBC = cross(point, B, C);
	Fixed cCA = cross(point, C, A);

	if (cAB == 0 or cBC == 0 or cCA == 0)
		return (false);

	bool hasNeg = (cAB < 0) or (cBC < 0) or (cCA < 0);
	bool hasPos = (cAB > 0) or (cBC > 0) or (cCA > 0);

	return not (hasNeg && hasPos);
}

static void test(Point const& a, Point const& b, Point const& c,
                 Point const& p, std::string name)
{
	std::cout << name << ": ";
	bool inside = bsp(a, b, c, p);
	if (inside)
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "OUTSIDE" << std::endl;
}

int main()
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 3);

	// Points de test
	Point p1(2, 1);   // inside
	Point p2(2, 3);   // vertex
	Point p3(1, 0);   // edge
	Point p4(5, 1);   // outside
	Point p5(2, -1);  // outside
	Point p6(3, 1);   // inside
	Point p7(1, 2);   // outside
	Point p8(10, 10); // far outside

	std::cout << "Triangle: A(0,0), B(4,0), C(2,3)\n\n";

	test(a, b, c, p1, "Test 1  (2,1)   ");
	test(a, b, c, p2, "Test 2  (2,3)   ");
	test(a, b, c, p3, "Test 3  (1,0)   ");
	test(a, b, c, p4, "Test 4  (5,1)   ");
	test(a, b, c, p5, "Test 5  (2,-1)  ");
	test(a, b, c, p6, "Test 6  (3,1)   ");
	test(a, b, c, p7, "Test 7  (1,2)   ");
	test(a, b, c, p8, "Test 8  (10,10) ");

	return 0;
}
