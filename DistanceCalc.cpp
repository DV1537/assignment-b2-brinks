#include "DistanceCalc.h"
using namespace std;

double DistanceCalc::getDistance(Point lPointOne, Point lPointTwo, Point point) {
	double minimumDistance;
	Point vector = getVector(lPointTwo, lPointOne);
	Point vectorTwo = getVector(point, lPointOne);
	double r = calculateDotProduct(vector, vectorTwo);
	r = r / caluclateMagnitude(vector.getX(), vector.getY());
	
	if (r < 0) {
		Point lengthVector = getVector(point, lPointOne);
		minimumDistance = caluclateMagnitude(lengthVector.getX(), lengthVector.getY());
	}
	else if (r > 1) {
		Point lengthVector = getVector(lPointTwo, point);
		minimumDistance = caluclateMagnitude(lengthVector.getX(), lengthVector.getY());
	}
	else {
		minimumDistance = sqrt(pow(caluclateMagnitude(vectorTwo.getX(), vectorTwo.getY()), 2) - (r * pow(caluclateMagnitude(vector.getX(), vector.getY()), 2)));
	}
		
	return minimumDistance;
}

double DistanceCalc::getDistance(Point one, Point two) {
	Point vector = getVector(one, two);
	return sqrt(pow(vector.getX(), 2) + pow(vector.getY(), 2));
}

Point DistanceCalc::getVector(Point one, Point two) {
	double vectorX = one.getX() - two.getX();
	double vectorY = one.getY() - two.getY();

	return Point(vectorX, vectorY);
}

double DistanceCalc::calculateDotProduct(Point one, Point two) {
	return (one.getX() * two.getY()) - (one.getY() * two.getX());
}

double DistanceCalc::caluclateMagnitude(double x, double y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}