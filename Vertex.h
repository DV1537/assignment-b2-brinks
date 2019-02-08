#ifndef VERTICE_H
#define VERTICE_H

#include "Shape.h"

class SinglePoint : public Shape {
public:
	SinglePoint(Point thePoint): one(thePoint) {};
	string getType() const;
	double getArea();
	Point *getPoints() const;
	int getCount() const { return 1; };
	double getCircumference();
	Point *getBoundaryBox();
	Point getPosition();
	friend ostream &operator <<(ostream &os, const SinglePoint &rhs);
	void operator=(const SinglePoint &rhs);
private:
	Point one;
	const string TYPE = "Point";
};

#endif 