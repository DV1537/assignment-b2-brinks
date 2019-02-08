#include "Triangle.h"

string Triangle::getType() const {
	return this->TYPE;
}

double Triangle::getArea() {
	double area = (
			(this->pointTwo.getX() - this->pointOne.getX()) * 
			(this->pointThree.getY() - this->pointOne.getY()) - 
			(this->pointThree.getX() - this->pointOne.getX()) * 
			(this->pointTwo.getY() - this->pointOne.getY())
		) / 2.0;
	return area > 0.0 ? area : -area;
}

Point *Triangle::getPoints() const {
	Point *points = new Point[3];
	points[0] = this->pointOne;
	points[1] = this->pointTwo;
	points[2] = this->pointThree;

	return points;
}

double Triangle::getCircumference() {
	return this->getSideLength(this->pointOne, this->pointTwo) + 
		this->getSideLength(this->pointTwo, this->pointThree) + 
		this->getSideLength(this->pointThree, this->pointOne);
}

Point Triangle::getPosition() {
	double centerX;
	double centerY;
	centerX = (pointOne.getX() + pointTwo.getX() + pointThree.getX()) / 3;
	centerY = (pointOne.getY() + pointTwo.getY() + pointThree.getY()) / 3;
	return Point(centerX, centerY);
}

Point* Triangle::getBoundaryBox() {
	Point *points = new Point[2]();
	double leftmostX = this->pointOne.getX();
	double topY = this->pointOne.getY();
	double bottomY = this->pointOne.getY();
	double rightmostX = this->pointOne.getX();

	if (pointTwo.getX() > leftmostX)
		rightmostX = pointTwo.getX();
	else
		leftmostX = pointTwo.getX();
	if (pointTwo.getY() > topY)
		topY = pointTwo.getY();
	else
		bottomY = pointTwo.getY();

	if (pointThree.getX() < leftmostX)
		leftmostX = pointThree.getX();
	else if (pointThree.getX() > rightmostX)
		rightmostX = pointThree.getX();

	if (pointThree.getY() > topY)
		topY = pointThree.getY();
	else if (pointThree.getY() < bottomY)
		bottomY = pointThree.getY();

	points[0] = Point(leftmostX, topY);
	points[1] = Point(rightmostX, bottomY);
	
	return points;
}

void Triangle::operator=(const Triangle &rhs) {
	this->pointOne = rhs.pointOne;
	this->pointTwo = rhs.pointTwo;
	this->pointThree = rhs.pointThree;
}

ostream &operator<<(ostream &os, const Triangle &rhs) {
	os << rhs.pointOne << +" " << rhs.pointTwo << +" " << rhs.pointThree << endl;
	return os;
}

double Triangle::getSideLength(Point one, Point two) {
	return sqrt(pow(two.getX() - one.getX(), 2) + pow(two.getY() - one.getY(), 2));
}