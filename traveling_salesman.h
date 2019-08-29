#pragma once

#include "node.h"
#include "renderer.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

class TravelingSalesman {
public:
	void solveNN();
	void printPath();
	void printStats(bool);
	void printPoints();
	TravelingSalesman(const int);
	TravelingSalesman(const int, const double, const double);

private:
	std::vector<Node> points;
	std::vector<Node> path;
	double min = 0;
	double max = 100;

	void generatePoints(int);
	void drawIncompletePath();
	void drawFinalPath();
	double getPathDistance();
	double randomDouble();
};