#pragma once
#include "Node.h"
#include "Coordinates.h"
#include "MyRectangle.h"
#include <vector>

const int BOXWIDTH = 6;
const int BOXHEIGHT = 2;
const int XPADDING = 25;
const int YPADDING = 5;

class BinaryTree : public Node {

public:
	Node* rootOfTree;
	Node* left;
	Node* right;

	BinaryTree();
	BinaryTree(int value, int x, int y);
	void SetRoot(int value, int x, int y);
	void InsertNodes(int value);
	void InsertNodesAt(Node* ptr, int value, int level);

	bool IsFull(Node* ptr); // ptr = Pointer To Root
	bool IsComplete(Node* ptr);
	bool IsPerfect(Node* ptr);

	int DebthOfTree(Node* ptr);

	int TotalParentCount(Node* ptr);
	void TotalParentString(Node* ptr);
	int TotalLeafCount(Node* ptr);
	void TotalLeafString(Node* ptr);
	int TotalCount(Node* ptr);

	void PreOrder(Node* ptr);
	void InOrder(Node* ptr);
	void PostOrder(Node* ptr);
	void PrintAt(Node* ptr, int xParent = -1, int yParent = -1);
	void Print();
};