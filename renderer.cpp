#include "renderer.h"

void drawLines(std::vector<Node> points) {

	glColor3f(0, 1, 0); // Green.
	glBegin(GL_LINES);
	for (int i = 1; i < points.size(); i++) {
		if (points[i].x == -100 && points[i].y == -100) {
			break;
		}
		glVertex2d(points[i].x, points[i].y);
		glVertex2d(points[i-1].x, points[i-1].y);

	}
	glEnd();
}

void drawLine(Node alpha, Node beta, float r, float g, float b) {
	glColor3f(r, g, b);
	glBegin(GL_LINES);
	glVertex2d(alpha.x, alpha.y);
	glVertex2d(beta.x, beta.y);
	glEnd();
}


void drawPoints(std::vector<Node> points) {
	glColor3f(1, 1, 1); // White.
	glBegin(GL_POINTS);
	for (Node a : points) {
		glVertex2d(a.x, a.y);
	}
	glEnd();
}

void render() {
	glutPostRedisplay();
	glFlush();
	glClear(GL_COLOR_BUFFER_BIT);
}
