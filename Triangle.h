#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Shape.h"
#include <string>
#include <math.h>

using namespace std;

class Triangle : public Shape
{

public:
	Triangle(Point one, Point two, Point three) : pointOne(one), pointTwo(two), pointThree(three) {}
	Triangle() : pointOne(0, 0), pointTwo(0, 0), pointThree(0, 0) {}
	string getType() const;
	double getArea();
	Point *getPoints() const;
	int getCount() const { return 3; };
	double getCircumference();
	Point getPosition();
	Point *getBoundaryBox();
	void operator=(const Triangle& rhs);
	friend ostream& operator<<(ostream& os, const Triangle& rhs);

private:
	Point pointOne;
	Point pointTwo;
	Point pointThree;
	const string TYPE = "Triangle";

	double getSideLength(Point one, Point two);
};

#endif