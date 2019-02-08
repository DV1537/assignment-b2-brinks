#include "Shape.h"

string Shape::getType() const {
	return this->TYPE;
}

double Shape::getArea() {
	return 0;
}

double Shape::getCircumference() {
	return 0;
}

Point *Shape::getBoundaryBox() {
	Point *points = new Point[1];
	
	points[0] = Point(0, 0);

	return points;
}

Point Shape::getPosition() {
	return Point(0,0);
}

double Shape::distance(Shape &s) {
	return 0;
}

