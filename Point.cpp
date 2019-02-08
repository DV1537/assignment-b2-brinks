#include "Point.h"
#include <iomanip>

double Point::getX() {
	return this->xPos;
}

double Point::getY() {
	return this->yPos;
}

ostream& operator<<(ostream& os, const Point& rhs) {
	os << setprecision(3) << fixed <<"(" << rhs.xPos << "," << rhs.yPos << ")";
	return os;
}

