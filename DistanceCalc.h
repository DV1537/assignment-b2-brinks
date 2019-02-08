#ifndef DISTANCECALC_H
#define DISTANCECALC_H

#include "Point.h"
#include <math.h>

class DistanceCalc {
protected: 
	DistanceCalc() {};
public: 
	static double getDistance(Point lineOne, Point lineTwo, Point point);
	static double getDistance(Point one, Point two);
private:
	static Point getVector(Point one, Point two);
	static double calculateDotProduct(Point one, Point two);
	static double caluclateMagnitude(double x, double y);
};

#endif