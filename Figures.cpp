#include "Figures.h"

void Figures::addShape(Shape *newShape) {
	if (this->shapes == nullptr) {
		shapes = new Shape*[1];
		shapes[this->count] = newShape;
		this->count++;
	}
	else {
		Shape **tmpShapes = new Shape*[this->count + 1];
		int i = 0;
		for (; i < this->count; i++) {
			tmpShapes[i] = this->shapes[i];
		}
		tmpShapes[i] = newShape;

		delete [] shapes;
		this->shapes = tmpShapes;
		this->count++;
	}
}

Point *Figures::boundaryBox() {
	Point *points = new Point[2];
	if (this->count == 0) {
		points[0] = Point(0, 0);
		points[1] = Point(0, 0);
		return points;
	}
	Point *firstBoundaryBox = this->shapes[0]->getBoundaryBox();
	double leftmostX = firstBoundaryBox[0].getX();
	double rightmostX = firstBoundaryBox[1].getX();
	double topY = firstBoundaryBox[0].getY();
	double bottomY = firstBoundaryBox[1].getY();
	for (int i = 1; i < this->count; i++) {
		Point *boundaryPoints = this->shapes[i]->getBoundaryBox();
		if (boundaryPoints[0].getX() < leftmostX)
			leftmostX = boundaryPoints[0].getX();
		if (boundaryPoints[1].getX() > rightmostX)
			rightmostX = boundaryPoints[1].getX();
		if (boundaryPoints[0].getY() > topY)
			topY = boundaryPoints[0].getY();
		if (boundaryPoints[1].getY() < bottomY)
			bottomY = boundaryPoints[1].getY();
	}

	points[0] = Point(leftmostX, topY);
	points[1] = Point(rightmostX, bottomY);
	return points;
};

Shape **Figures::getClosest(Shape *location, int &n) {
	ShapeWDistance *shapeDistances = new ShapeWDistance[this->count];
	for (int i = 0; i < this->count; i++) {
		double shortestDistance = 10000000000;
		double shortestToCenter = 10000000000;
		double shortestToShapePoints = 10000000000;
		int comparedShapePointCount = this->shapes[i]->getCount();
		Point *comparedShapePoints = this->shapes[i]->getPoints();
		bool inside = isInside(location, this->shapes[i]);

		shapeDistances[i].shape = this->shapes[i];
		if (!inside) {
			for (int j = 0; j < location->getCount(); j++) {
				double shortestDistanceCalc;
				double distanceToCenter = 10000000000;
				if (comparedShapePointCount == 1) {
					shortestDistanceCalc = DistanceCalc::getDistance(
						location->getPoints()[j],
						comparedShapePoints[0]
					);
				}
				else {
					for (int k = 0; k < comparedShapePointCount - 1; k++) {
						shortestDistanceCalc = DistanceCalc::getDistance(
							comparedShapePoints[k],
							comparedShapePoints[k + 1],
							location->getPoints()[j]
						);
					}
				}
				shortestDistance = shortestDistanceCalc < shortestDistance ? shortestDistanceCalc : shortestDistance;
			}
			shapeDistances[i].distance = shortestDistance;
		}
		else {
			// Location shape is inside or intersecting the compared shape, so distance is 0
			shapeDistances[i].distance = 0;
		}


	}
	for (int i = 0; i < this->count; i++) {
		cout<<shapeDistances[i].distance<<endl;
	}
	qSort(shapeDistances, 0, this->count);
	int amountOfShapes = this->count < n ? this->count : n;
	Shape **returnShapes = new Shape*[amountOfShapes];
	for (int i = 0; i < amountOfShapes; i++) {
		returnShapes[i] = shapeDistances[i].shape;
	}

	n = amountOfShapes;

	return returnShapes;
}

bool Figures::isInside(Shape *pointShape, Shape *comparisonShape) {
	if (comparisonShape->getCount() < 3) {
		return false;
	}
	
	int polygonCount = comparisonShape->getCount();
	Point *polygonPoints = comparisonShape->getPoints();
	for (int i = 0; i < pointShape->getCount(); i++) {
		Point comparisonPoint = pointShape->getPoints()[i];
		int k = polygonCount - 1;
		bool inside = false;
		// Using ray-casting to the right
		for (int j = 0; j < polygonCount; j++) {
			if ((polygonPoints[j].getY() > comparisonPoint.getY()) != 
				(polygonPoints[k].getY() > comparisonPoint.getY() &&
				(comparisonPoint.getX() < (polygonPoints[k].getX() - polygonPoints[j].getX()) *
				(comparisonPoint.getY() - polygonPoints[j].getY()) /
					(polygonPoints[k].getY() - polygonPoints[j].getY()) +
					polygonPoints[j].getX()))
				) {
				inside = !inside;
			}
			k = j;
		}
		if (inside)
			return inside;
	}
	return false;
}

void Figures::qSort(ShapeWDistance *shapes, int min, int max) {
	int mid = (min + max) / 2;
	int i = min; 
	int j = max;
	double pivot = shapes[mid].distance;
	while (min < j || i < max) {
		while (shapes[i].distance < pivot)
			i++;
		while (shapes[j].distance > pivot)
			j--;

		if (i <= j) {
			swap(shapes, i, j);
			i++;
			j--;
		}
		else {
			if (min < j)
				qSort(shapes, min, j);
			if (i < max)
				qSort(shapes, i, max);
			return;
		}
	}
}

void Figures::swap(ShapeWDistance *shapes, int first, int second) {
	ShapeWDistance tmp = shapes[first];
	shapes[first] = shapes[second];
	shapes[second] = tmp;
}