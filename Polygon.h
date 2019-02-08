#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"
#include "Shape.h"
#include <string>
#include <math.h>

using namespace std;

class Polygon : public Shape
{
public:
	Polygon(Point *p, int c) : points(p), count(c) {}
	Polygon() : points(nullptr), count(0) {}
	Polygon(const Polygon &polygon) : count(polygon.getCount()), points(polygon.getPoints()) {};
	~Polygon() { delete[] points; }
	Point* getPoints() const { return points; }
	int getCount() const { return count; }
	string getType() const;
	double getArea();
	double getCircumference();
	Point getPosition();
	bool isConvex();
	friend Polygon operator+(Polygon lhs, Point rhs); 
	friend Polygon operator+(Polygon lhs, Polygon rhs);
	void operator=(const Polygon& rhs);
	Point *getBoundaryBox();
	friend ostream& operator<<(ostream& os, const Polygon& rhs);

private:
	Point* points = nullptr;
	int count = 0;
	const string TYPE = "Polygon";
	double getSideLength(Point one, Point two);
};

#endif