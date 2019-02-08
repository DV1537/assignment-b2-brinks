#ifndef LINE_H
#define LINE_H
#include "Point.h"
#include "Shape.h"
#include <string>

using namespace std;

class Line : public Shape
{

public:
	Line(Point one, Point two) : pointOne(one), pointTwo(two) {}
	Line() : pointOne(0, 0), pointTwo(0, 0) {}
	string getType() const;
	double getArea();
	Point *getPoints() const;
	int getCount() const { return 2; };
	double getCircumference();
	Point *getBoundaryBox();
	Point getPosition();
	friend ostream& operator<<(ostream &os, const Line& rhs);
	void operator=(const Line &rhs);

private:
	Point pointOne;
	Point pointTwo;
	const string TYPE = "Line";
};

#endif