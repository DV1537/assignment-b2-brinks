#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point.h"
#include <iostream>

using namespace std;

class Shape
{
public:
	Shape() {}
	virtual ~Shape() {};
	virtual string getType() const = 0;
	virtual double getArea() = 0;
	virtual double getCircumference() = 0;
	virtual Point getPosition() = 0;
	virtual Point *getBoundaryBox() = 0;
	virtual Point *getPoints() const = 0;
	virtual int getCount() const = 0;
	double distance(Shape &s);
private: 
	const string TYPE = "Shape";
};

#endif