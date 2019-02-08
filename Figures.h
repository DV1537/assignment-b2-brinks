#ifndef FIGURES_H
#define FIGURES_H

#include "Shape.h"
#include "DistanceCalc.h"
#include "ShapeWDistance.h"

using namespace std;

class Figures {
public:
	Figures() : shapes(nullptr), count(0) {};
	~Figures() { 
		for (int i = 0; i < this->count; i++)
			delete this->shapes[i];
		delete [] this->shapes; 
	};
	void addShape(Shape *s);
	Point *boundaryBox();
	Shape **getClosest(Shape *location, int &n);
private: 
	Shape **shapes;
	int count;
	void qSort(ShapeWDistance *shapes, int min, int max);
	void swap(ShapeWDistance *shapes, int first, int second);
	bool isInside(Shape *comparisonShape, Shape *pointShape);
};

#endif