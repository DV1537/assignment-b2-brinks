#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Point.h"
#include "Figures.h"
#include "SinglePoint.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

using namespace std;

Shape *getShape(Point *shapePoints, int count);
Point *getLinePoints(string line, int &count);
bool validCoordinate(string coordinate);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cout << "File-path argument missing\n";
		return EXIT_FAILURE;
	}

	ifstream file(argv[1]);
	if (!file.is_open()) {
		cout << "Could not open file.\n";
		return EXIT_FAILURE;
	}
	string line;
	Shape **testShapes = new Shape*[4];
	int numberOfShapes = 0;
	Figures figures;
	while (getline(file, line)) {
		int count = 0;
		Point *shapePoints = getLinePoints(line, count);
		if (shapePoints == nullptr) {
			cout << "Invalid number of coordinates, or coordinates incorrect. Need to be a multiple of two\n";
			return EXIT_FAILURE;
		}
		Shape *newShape = getShape(shapePoints, count);
		testShapes[numberOfShapes] = newShape;
		numberOfShapes++;
		figures.addShape(newShape);
	}

	Shape *point = new SinglePoint(Point(5, 5));
	int amount = 3;
	Shape **shapes = figures.getClosest(point, amount);

	for (int i = 0; i < amount; i++) {
		Point *points = shapes[i]->getPoints();
		cout << shapes[i]->getType() << endl;
		for (int j = 0; j < shapes[i]->getCount(); j++) {
			cout << points[j];
		}
		cout << endl << endl;
	}

	delete point;

	return EXIT_SUCCESS;
}

Point *getLinePoints(string line, int &count) {
	char delimeter = ' ';
	stringstream ss(line);
	string value;
	int coordinates = 0;
	string values[200];
	while (getline(ss, value, delimeter)) {
		values[coordinates] = value;
		coordinates++;
	}
	int i = 0;
	if ((coordinates % 2) != 0) {
		return nullptr;
	}

	Point *points = new Point[coordinates / 2];
	int numberOfPoints = 0;
	while (i < coordinates) {
		string coordinateOne;
		string coordinateTwo;
		coordinateOne = values[i];
		coordinateTwo = values[++i];
		if (validCoordinate(coordinateOne) && validCoordinate(coordinateTwo)) {
			double x = stod(coordinateOne);
			double y = stod(coordinateTwo);
			points[numberOfPoints] = Point(x, y);
			numberOfPoints++;
		}
		else
		{
			return nullptr;
		}
		i++;
	}

	count = coordinates / 2;

	return points;
}

bool validCoordinate(string coordinate) {
	char a = coordinate[0];
	bool dotFound = false;
	if (a < '0' && a > '9')
		return false;
	
	a = coordinate[coordinate.length() - 1];
	if (a < '0' && a > '9')
		return false;

	for (int i = 0; i < coordinate.length(); i++) {
		a = coordinate[i];
		if (a == '.' && !dotFound) 
			dotFound = true;
		else if (a == '.')
			return false;
		if (a != '.' && a < '0' && a > '9') {
			return false;
		}
	}

	return true;
}

Shape *getShape(Point *shapePoints, int count) {
	Shape *newShape;
	if (count == 1) {
		newShape = new SinglePoint(shapePoints[0]);
	}
	else if (count == 2) {
		newShape = new Line(shapePoints[0], shapePoints[1]);
	}
	else if (count == 3) {
		newShape = new Triangle(shapePoints[0], shapePoints[1], shapePoints[2]);
	}
	else {
		newShape = new Polygon(shapePoints, count);
	}

	return newShape;
}