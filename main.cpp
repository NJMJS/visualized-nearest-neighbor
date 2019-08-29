#include "traveling_salesman.h"
#include <iostream>

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello world :D");

	TravelingSalesman test = TravelingSalesman(5000, -0.95, 0.95);
	test.solveNN();
	test.printStats(true);
	//test.printPath();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	int x;
	std::cin >> x;

	
	/*glutDisplayFunc(displayMe);
	glutMainLoop();*/

	return 0;
}