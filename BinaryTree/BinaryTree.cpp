#include <iostream>
#include <string>
#include <Windows.h>
#include <queue>
#include <vector>
#include <list>
#include "BinaryTree.h"
#include "MyRectangle.h"
#include "Connect.h"
#include <algorithm>

BinaryTree::BinaryTree() {

}
BinaryTree::BinaryTree(int value, int x, int y) {
	SetRoot(value, x, y);
}
void BinaryTree::SetRoot(int value, int x, int y) {
	rootOfTree = new Node(value, x, y);
	rootOfTree->parent = rootOfTree;
}
void BinaryTree::InsertNodes(int value) {
	InsertNodesAt(rootOfTree, value, level);
}
void BinaryTree::InsertNodesAt(Node* ptr, int value, int level) {
	if (ptr == nullptr) {
		rootOfTree = new Node(value, x, y);
	}
	else if (value < ptr->getValue()) {
		if (ptr->left != nullptr) {
			level++;
			InsertNodesAt(ptr->left, value, level);
		}
		else {
			level++;
			int ycalc, xcalc;
			xcalc = ptr->x - (XPADDING - (level * 3));
			ycalc = rootOfTree->y + (level * 5);
			Node* temp;
			temp = new Node(value, xcalc, ycalc);
			ptr->left = temp;
		}
	}
	else if (value > ptr->getValue()) {
		if (ptr->right != nullptr) {
			level++;
			InsertNodesAt(ptr->right, value, level);
		}
		else {
			level++;
			int ycalc, xcalc;
			xcalc = ptr->x + (XPADDING - (level * 3));
			ycalc = rootOfTree->y + (level * 5);
			Node* temp;
			temp = new Node(value, xcalc, ycalc);
			ptr->right = temp;
		}
	}
}
int BinaryTree::DebthOfTree(Node* ptr) {
	if (!ptr) {
		return 0;
	}
	return 1 + max(DebthOfTree(ptr->left), DebthOfTree(ptr->right));
}
bool BinaryTree::IsFull(Node* ptr) {
	if (!ptr) {
		return true;
	}
	if (!ptr->left && !ptr->right) {
		return true;
	}
	if (ptr->left && ptr->right) {
		return IsFull(ptr->left) && IsFull(ptr->right);
	}
	return false;
}
bool BinaryTree::IsComplete(Node* ptr) {
	if (ptr->left == nullptr && ptr->right == nullptr) {
		return true;
	}
	if (ptr->left != nullptr && ptr->right != nullptr) {
		return IsComplete(ptr->left) && IsComplete(ptr->right);
	}
	if (ptr->left != nullptr) {
		return ptr->left->left == nullptr && ptr->left->right == nullptr;
	}
	if (ptr->right != nullptr) {
		return ptr->right->left == nullptr && ptr->right->right == nullptr;
	}
}
bool BinaryTree::IsPerfect(Node* ptr) {
	if (!ptr) {
		return true;
	}
	int leftHeight = DebthOfTree(ptr->left);
	int rightHeight = DebthOfTree(ptr->right);
	if (leftHeight != rightHeight) {
		return false;
	}
	return IsPerfect(ptr->left) && IsPerfect(ptr->right);
}
int BinaryTree::TotalParentCount(Node* ptr) {
	if (ptr == nullptr || (ptr->left == nullptr && ptr->right == nullptr)) {
		return 0;
	}
	return TotalParentCount(ptr->left) + TotalParentCount(ptr->right) + 1;
}
void BinaryTree::TotalParentString(Node* ptr) {
	if (ptr == nullptr)
		return;
	if (ptr->left != nullptr && ptr->right != nullptr)
		std::cout << " |" << ptr->getValue() << "|";
	TotalParentString(ptr->left);
	TotalParentString(ptr->right);
}
int BinaryTree::TotalLeafCount(Node* ptr) {
	if (ptr == nullptr) {
		return 0;
	}
	if (ptr->left == nullptr && ptr->right == nullptr) {
		return 1;
	}
	return TotalLeafCount(ptr->left) + TotalLeafCount(ptr->right);
}
void BinaryTree::TotalLeafString(Node* ptr) {
	if (ptr == nullptr)
		return;
	if (ptr->left == nullptr && ptr->right == nullptr)
		std::cout << " |" << ptr->getValue() << "|";
	TotalLeafString(ptr->left);
	TotalLeafString(ptr->right);
}
int BinaryTree::TotalCount(Node* ptr) {
	if (!ptr)
		return 0;
	return 1 + TotalCount(ptr->left) + TotalCount(ptr->right);
}
void BinaryTree::PreOrder(Node* ptr) {
	if (ptr == nullptr)
		return;
	std::cout << ptr->getValue() << " ";
	PreOrder(ptr->left);
	PreOrder(ptr->right);
}
void BinaryTree::InOrder(Node* ptr) {
	if (ptr == nullptr)
		return;
	InOrder(ptr->left);
	std::cout << ptr->getValue() << " ";
	InOrder(ptr->right);
}
void BinaryTree::PostOrder(Node* ptr) {
	if (ptr == nullptr)
		return;
	PostOrder(ptr->left);
	PostOrder(ptr->right);
	std::cout << ptr->getValue() << " ";
}
void BinaryTree::PrintAt(Node* ptr, int xParent, int yParent) {
	std::string stringValue = std::to_string(ptr->getValue());
	MyRectangle box;
	Connect C;

	if (ptr->left == nullptr && ptr->right == nullptr) {
		box.DrawSkelaton(ptr->x - 3, ptr->y - 3, BOXWIDTH - 1, BOXHEIGHT, stringValue, 2);
	}
	else if (ptr->parent != nullptr && (ptr->left != nullptr || ptr->right != nullptr)) {
		box.DrawSkelaton(ptr->x - 3, ptr->y - 3, BOXWIDTH - 1, BOXHEIGHT, stringValue, 5);
	}
	else {
		box.DrawSkelaton(ptr->x - 3, ptr->y - 3, BOXWIDTH - 1, BOXHEIGHT, stringValue, 3);
	}
	if (xParent != -1) {
		int xOne, yOne,
			xTwo, yTwo;
		xOne = ptr->x;
		yOne = ptr->y;
		xTwo = xParent;
		yTwo = yParent;

		setColor(15);
		C.Link(xTwo, yTwo, xOne, yOne - BOXHEIGHT - 1);
		gotoxy(xOne, yOne - BOXHEIGHT - 1);
		std::cout << char(193);
		gotoxy(xTwo, yTwo - 1);
		std::cout << char(194);
	}
	if (ptr->right != nullptr) {
		PrintAt(ptr->right, ptr->x, ptr->y);
	}
	if (ptr->left != nullptr) {
		PrintAt(ptr->left, ptr->x, ptr->y);
	}
}
void BinaryTree::Print() {

	showConsoleCursor(false);
	PrintAt(rootOfTree);

	setColor(9);
	gotoxy(0, 0);
	std::cout << "Amount Of Nodes: |" << TotalCount(rootOfTree) << "|";

	setColor(4);
	std::cout << "\n\nCount Of Parent Nodes: |" << TotalParentCount(rootOfTree) << "|" << " -> Values: "; TotalParentString(rootOfTree);
	setColor(6);
	std::cout << "\n\nCount Of Leaf Nodes:   |" << TotalLeafCount(rootOfTree) << "|" << " -> Values: "; TotalLeafString(rootOfTree);

<<<<<<< HEAD
	C.setColor(5);
=======
	setColor(5);
>>>>>>> 8cb55af (Third Commit)
	std::cout << "\n\nPre-Order:  ";
	PreOrder(rootOfTree);
	setColor(3);
	std::cout << "\nIn-Order:   ";
	InOrder(rootOfTree);
	setColor(2);
	std::cout << "\nPost-Order: ";
	PostOrder(rootOfTree);

	setColor(14);
	std::cout << "\n\nDebth Of Tree: |" << DebthOfTree(rootOfTree) << "|";

	setColor(12);
	if (IsFull(rootOfTree) && IsPerfect(rootOfTree)) {
		std::cout << "\n\nTree Is: |Full & Perfect|";
	}
	else if (IsFull(rootOfTree)) {
		std::cout << "\n\nTree Is: |Full|";
	}
	else if (IsComplete(rootOfTree)) {
		std::cout << "\n\n|Tree Is: |Complete|";
	}
	else if (IsPerfect(rootOfTree)) {
		std::cout << "\n\n|Tree Is: |Perfect|";
	}
	else {
		std::cout << "\n\nThe Tree Is Neither Full, Complete, Nor Perfect." << std::endl;
	}

	gotoxy(90, 28);
	setColor(31);
	std::cout << " Created By: *Geo Hernandez* ";
}