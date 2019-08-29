#include "node.h"

double Node::distance(Node point)
{
	return sqrt(pow(double(x - point.x), 2) + pow(double(y - point.y), 2));
}

void Node::setPoints(double x, double y) {
	this->x = x;
	this->y = y;
}
