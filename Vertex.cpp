#include "Vertex.h"

string SinglePoint::getType() const {
	return this->TYPE;
}

double SinglePoint::getArea() {
	return 0;
}

Point *SinglePoint::getPoints() const {
	Point *points = new Point[1];
	points[0] = this->one;
	return points;
}

double SinglePoint::getCircumference() {
	return 0;
}

Point *SinglePoint::getBoundaryBox() {
	Point *points = new Point[2];

	points[0] = one;
	points[1] = one;

	return points;
}

Point SinglePoint::getPosition() {
	return one;
}

ostream &operator<<(ostream &os, const SinglePoint &rhs) {
	os << rhs.one << endl;
	return os;
}

void SinglePoint::operator=(const SinglePoint &rhs) {
	this->one = rhs.one;
}