#include "Line.h"

string Line::getType() const {
	return this->TYPE;
}

double Line::getArea() {
	return -1;
}

Point *Line::getPoints() const {
	Point *points = new Point[2];
	points[0] = this->pointOne;
	points[1] = this->pointTwo;

	return points;
}

double Line::getCircumference() {
	return sqrt(pow(pointOne.getX() - pointTwo.getX(), 2) + pow(pointOne.getY() - pointTwo.getY(), 2));
}

Point Line::getPosition() {
	double xPos;
	double yPos;
	xPos = (pointOne.getX() + pointTwo.getX()) / 2;
	yPos = (pointOne.getY() + pointTwo.getY()) / 2;
	return Point(xPos, yPos);
}

Point *Line::getBoundaryBox() {
	Point *points = new Point[2]();
	double rightmostX;
	double leftmostX;
	double topY;
	double bottomY;
	if (pointOne.getX() > pointTwo.getX()) {
		rightmostX = pointOne.getX();
		leftmostX = pointTwo.getX();
	}
	else {
		rightmostX = pointTwo.getX();
		leftmostX = pointOne.getX();
	}
	if (pointOne.getY() > pointTwo.getY()) {
		topY = pointOne.getY();
		bottomY = pointTwo.getY();
	}
	else {
		topY = pointTwo.getY();
		bottomY = pointOne.getY();
	}

	points[0] = Point(leftmostX, topY);
	points[1] = Point(rightmostX, bottomY);

	return points;
}

ostream &operator<<(ostream &os, const Line &rhs) {
	os << rhs.pointOne << " " << rhs.pointTwo << endl;
	return os;
}

void Line::operator=(const Line &rhs) {
	this->pointOne = rhs.pointOne;
	this->pointTwo = rhs.pointTwo;
}