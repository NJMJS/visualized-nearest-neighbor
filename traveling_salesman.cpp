#include "traveling_salesman.h"


void TravelingSalesman::solveNN() {
	Node nullNode = Node();
	nullNode.setPoints(-100, -100);
	path.resize(points.size());
	std::fill(path.begin(), path.end(), nullNode);

	std::vector<bool> visited;
	visited.resize(points.size());
	std::fill(visited.begin(), visited.end(), false);

	visited[0] = true;
	path[0] = points[0];

	for (int i = 1; i < points.size(); i++) {
		double best = INT_MAX;
		int bestLoc = -1;
		for (int j = 0; j < points.size(); j++) {
			if (!visited[j]) {
				double dist = path[i - 1].distance(points[j]);

				// Draw here to show progress!
				/*drawIncompletePath(); // Current path.
				drawLine(path[i - 1], points[j], 1, 0, 0); // Proposed location.
				if (bestLoc > 0) {
					drawLine(path[i - 1], points[bestLoc], 1, 1, 0.5); // Current best.
				}
				render();*/

				if (dist < best) {
					best = dist;
					bestLoc = j;
				}
			}
		}
		path[i] = points[bestLoc];

		// Draw the current route.
		drawIncompletePath();
		render();

		visited[bestLoc] = true;
	}

	// Show the final path.
	drawFinalPath();
	render();
}

void TravelingSalesman::printPath() {
	std::cout << "Path:" << std::endl;
	for (int i = 0; i < path.size(); i++) {
		std::cout << path[i].x << " " << path[i].y << std::endl;
	}
}

void TravelingSalesman::printStats(bool isNN) {
	if (isNN) {
		std::cout << "Nearest Neighbor stats:" << std::endl;
	}
	else {
		std::cout << "Weighted Nearest Neighbor stats:" << std::endl;
	}

	std::cout << "Distance: " << getPathDistance() << std::endl;
}

void TravelingSalesman::printPoints() {
	for (int i = 0; i < points.size(); i++) {
		std::cout << points[i].x << " " << points[i].y << std::endl;
	}
}

TravelingSalesman::TravelingSalesman(const int numPoints){
	TravelingSalesman::generatePoints(numPoints);
}

TravelingSalesman::TravelingSalesman(
	const int numPoints, const double min, const double max) {
	this->max = max;
	this->min = min;

	TravelingSalesman::generatePoints(numPoints);
}

void TravelingSalesman::generatePoints(const int numPoints) {
	
	this->points.resize(numPoints);

	for (int i = 0; i < numPoints; i++) {
		Node temp = Node();
		temp.setPoints(randomDouble(), randomDouble());
		// TODO: Prevent duplicates!
		points[i] = temp;
	}
}

void TravelingSalesman::drawIncompletePath() {
	drawPoints(points);
	drawLines(path);
}

void TravelingSalesman::drawFinalPath() {
	drawIncompletePath();
	drawLine(path[0], path[path.size() - 1], 0, 1, 0);
}

double TravelingSalesman::getPathDistance() {
	double dist = 0;
	for (int i = 1; i < path.size(); i++) {
		dist += path[i].distance(path[i - 1]);
	}
	dist += path[0].distance(path[path.size() - 1]);
	return dist;
}

double TravelingSalesman::randomDouble() {
	static bool calledSrand = false;
	if (!calledSrand) {
		srand(time(0));
		calledSrand = true;
	}
	return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}
