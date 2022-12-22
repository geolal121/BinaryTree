#include "Node.h"

Node::Node() {
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	level = 0;
}
Node::Node(int val, int xx, int yy) : Node() {
	x = xx;
	y = yy;
	nodeValue = val;
}
int Node::getValue() {
	return nodeValue;
}