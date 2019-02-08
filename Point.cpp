#include "Point.h"

double Point::getX() {
	return this->xPos;
}

double Point::getY() {
	return this->yPos;
}

ostream& operator<<(ostream& os, const Point& rhs) {
	os << "(" << rhs.xPos << "," << rhs.yPos << ")";
	return os;
}

