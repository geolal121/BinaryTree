#pragma once
#include <string>
#include <fstream>
#include "Coordinates.h"
#include <vector>

class Node : public Coordinates {
public:
	int x, y;
	int nodeValue;
	int level;
	Node* parent;
	Node* left;
	Node* right;
	Node();
	Node(int value, int xx, int yy);
	int getValue();
};