// Created By: Heriberto Hernandez
// Pushed To GitHub: 12/21/22
#include "BinaryTree.h"
#include "Node.h"

void main() {
	BinaryTree B;

	B.SetRoot(20, 58, 10);

	// Right
	B.InsertNodes(30);
	B.InsertNodes(45);   // Comment To Check If Only Complete
	B.InsertNodes(25);
	B.InsertNodes(50);  // Comment To Check If Only Complete Or This To Check If Perfect
	B.InsertNodes(40); // Comment To Check If Only Complete Or This To Check If Perfect

	// Left
	B.InsertNodes(10);
	B.InsertNodes(15);
	B.InsertNodes(5);

	B.Print();

	while (1);
}