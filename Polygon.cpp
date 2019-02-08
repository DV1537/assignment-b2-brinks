#include "Polygon.h"

string Polygon::getType() const {
	return this->TYPE;
}

double Polygon::getArea() {
	double calcPos = 0;
	double calcNeg = 0;
	int j = this->count - 1;

	if (!isConvex()) {
		return -1;
	}

	for (int i = 0; i < this->count; i++) {
		Point tmpOne = this->points[j];
		Point tmpTwo = this->points[i];
		calcPos += tmpOne.getX() * tmpTwo.getY();
		calcNeg += tmpTwo.getX() * tmpOne.getY();
		j = i;
	}

	return 	(calcPos - calcNeg) * 0.5;
}

double Polygon::getCircumference() {
	double circumference = 0.0;
	int j = this->count - 1;
	for (int i = 0; i < this->count; i++) {
		circumference += getSideLength(points[i], points[j]);
		j = i;
	}
	return circumference;
}

Point Polygon::getPosition() {
	int numberOfVertices = this->count;
	double sumX = 0;
	double sumY = 0;
	int i = 0;
	for (; i < numberOfVertices; i++) {
		sumX += this->points[i].getX() / numberOfVertices;
		sumY += this->points[i].getY() / numberOfVertices;
	}
	return Point(sumX, sumY);
}



bool Polygon::isConvex() {
	bool sign = false;
	int vertices = this->count;
	if (vertices < 4)
		return true;

	int i = 0;
	for (; i < vertices	; i++) {
		double xOne = this->points[(i + 2) % vertices].getX() - this->points[(i + 1) % vertices].getX();
		double yOne = this->points[(i + 2) % vertices].getY() - this->points[(i + 1) % vertices].getY();
		double xTwo = this->points[i].getX() - this->points[(i + 1) % vertices].getX();
		double yTwo = this->points[i].getY() - this->points[(i + 1) % vertices].getY();
		double crossproduct = (xOne * yTwo) - (yOne * xTwo);

		if (i == 0)
			sign = crossproduct > 0;
		else if (sign != (crossproduct > 0))
			return false;
	}
	return true;
}

Polygon operator+(Polygon lhs, Point rhs) {
	int totalCount = lhs.getCount() + 1;
	Point *tmpPoints = new Point[totalCount]();
	Point *lhsPoints = lhs.getPoints();
	int i = 0;
	for (; i < lhs.getCount(); i++) {
		tmpPoints[i] = lhsPoints[i];
	}
	tmpPoints[i] = rhs;
	Polygon newPolygon(tmpPoints, totalCount);
	return newPolygon;
}

Polygon operator+(Polygon lhs, Polygon rhs) {
	int totalCount = lhs.getCount() + rhs.getCount();
	Point *tmpPoints = new Point[totalCount];
	int i = 0;
	int j;
	for (; i < lhs.getCount(); i++) {
		tmpPoints[i] = lhs.getPoints()[i];
	}
	j = i;
	i = 0;
	for (; i < rhs.getCount(); i++) {
		tmpPoints[j] = rhs.getPoints()[i];
		j++;
	}
	return Polygon(tmpPoints, totalCount);
}

void Polygon::operator=(const Polygon &rhs) {
	int totalCount = rhs.getCount();
	Point *tmpPoints = new Point[totalCount]();
	this->count = totalCount;
	int i = 0;
	for (; i < totalCount; i++) {
		tmpPoints[i] = rhs.getPoints()[i];
	}
	this->points = tmpPoints;
}

ostream &operator<<(ostream &os, const Polygon &rhs) {
	int i = 0;
	Point *tmpPoints = rhs.getPoints();
	for (; rhs.getCount(); i++) {
		os << tmpPoints[i];
	}
	os << endl;
	return os;
}

double Polygon::getSideLength(Point one, Point two) {
	return sqrt(pow(two.getX() - one.getX(), 2) + pow(two.getY() - one.getY(), 2));
}

Point *Polygon::getBoundaryBox() {
	Point *bbPoints = new Point[2]();

	double leftmostX;
	double leftmostY;
	double rightmostX;
	double rightmostY;
	leftmostX = this->points[0].getX();
	leftmostY = this->points[0].getY();
	rightmostX = this->points[0].getX();
	rightmostY = this->points[0].getY();

	int i = 1;
	for (; i < this->count; i++) {
		Point tmpPoint = this->points[i];
		if (tmpPoint.getX() < leftmostX) {
			leftmostX = tmpPoint.getX();
		}
		if (tmpPoint.getY() > leftmostY) {
			leftmostY = tmpPoint.getY();
		}
		if (tmpPoint.getX() > rightmostX) {
			rightmostX = tmpPoint.getX();
		}
		if (tmpPoint.getY() < rightmostY) {
			rightmostY = tmpPoint.getY();
		}
	}

	bbPoints[0] = Point(leftmostX, leftmostY);
	bbPoints[1] = Point(rightmostX, rightmostY);
	
	return bbPoints;
}