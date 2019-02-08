#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point {
private:
	double xPos;
	double yPos;
public:
	Point(double x, double y) : xPos(x), yPos(y) {};
	Point() : xPos(0), yPos(0) {};
	double getX();
	double getY();
	friend ostream& operator<<(ostream& os, const Point& rhs);
};

#endif