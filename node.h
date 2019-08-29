#pragma once
#include <math.h>

class Node {
public:
	double distance(Node);
	void setPoints(double x, double y);
	double x;
	double y;
};