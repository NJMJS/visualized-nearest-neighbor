#pragma once
#include <GL/glut.h>
#include "node.h"
#include <vector>


void render();
void drawLines(std::vector<Node>);
void drawLine(Node, Node, float, float, float);
void drawPoints(std::vector<Node>);


