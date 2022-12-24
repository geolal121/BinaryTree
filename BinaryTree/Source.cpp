// Created By: Heriberto Hernandez
// Pushed To GitHub: 12/21/22
#include "BinaryTree.h"
#include "Node.h"

const int NUM_VALUES2 = 2;
const int NUM_VALUES4 = 4;
const int NUM_VALUES6 = 6;
const int NUM_VALUES8 = 8;
const int NUM_VALUES10 = 10;

void main() {

	char choiceAgain;
	int rootFromUser;
	int sizeOfArray;
	BinaryTree B;
	Coordinates C;
	B.showConsoleCursor(false);

	do {
		std::cout << "==== RULES ====" << std::endl;
		std::cout << "1) Enter Root" << std::endl;
		std::cout << "2) Enter Root Children" << std::endl;
		std::cout << "3) Left Nodes Are Smaller Than Right Nodes" << std::endl;
		std::cout << "\nEx." << std::endl;
		std::cout << "ROOT=> 50" << std::endl;
		std::cout << "     /   \\" << std::endl;
		std::cout << "    40    60" << std::endl;
		std::cout << "   / \\   / \\" << std::endl;
		std::cout << "  30  45 55 70" << std::endl;
		std::cout << " / \\ /\\ /\\  /\\" << std::endl;
		std::cout << " NULL  NULL NULL" << std::endl;
		Sleep(10000);
		system("cls");

		std::cout << "Enter Root Number: ";
		std::cin >> rootFromUser;
		B.SetRoot(rootFromUser, 60, 13);

		std::cout << "\n==SIZES OF TREE==" << std::endl;
		std::cout << "2)  Size 2" << std::endl;
		std::cout << "4)  Size 4" << std::endl;
		std::cout << "6)  Size 6" << std::endl;
		std::cout << "8)  Size 8" << std::endl;
		std::cout << "10) Size 10" << std::endl;
		std::cout << "\nEnter Size OF Tree: ";
		std::cin >> sizeOfArray;

		if (sizeOfArray == 2) {
			int values[NUM_VALUES2];
			std::cout << "\nEnter 2 Numbers:\n";
			for (int i = 0; i < NUM_VALUES2; i++) {
				std::cout << "\nEnter Number " << i + 1 << ": ";
				std::cin >> values[i];
			}
			for (int i = 0; i < NUM_VALUES2; i++) {
				int value = values[i];
				B.InsertNodes(value);
			}
		}
		else if (sizeOfArray == 4) {
			int values[NUM_VALUES4];
			std::cout << "\nEnter 4 Numbers:\n";
			for (int i = 0; i < NUM_VALUES4; i++) {
				std::cout << "\nEnter Number " << i + 1 << ": ";
				std::cin >> values[i];
			}
			for (int i = 0; i < NUM_VALUES4; i++) {
				int value = values[i];
				B.InsertNodes(value);
			}
		}
		else if (sizeOfArray == 6) {
			int values[NUM_VALUES6];
			std::cout << "\nEnter 6 Numbers:\n";
			for (int i = 0; i < NUM_VALUES6; i++) {
				std::cout << "\nEnter Number " << i + 1 << ": ";
				std::cin >> values[i];
			}
			for (int i = 0; i < NUM_VALUES6; i++) {
				int value = values[i];
				B.InsertNodes(value);
			}
		}
		else if (sizeOfArray == 8) {
			int values[NUM_VALUES8];
			std::cout << "\nEnter 8 Numbers:\n";
			for (int i = 0; i < NUM_VALUES8; i++) {
				std::cout << "\nEnter Number " << i + 1 << ": ";
				std::cin >> values[i];
			}
			for (int i = 0; i < NUM_VALUES8; i++) {
				int value = values[i];
				B.InsertNodes(value);
			}
		}
		else if (sizeOfArray == 10) {
			int values[NUM_VALUES10];
			std::cout << "\nEnter 10 Numbers:\n";
			for (int i = 0; i < NUM_VALUES10; i++) {
				std::cout << "\nEnter Number " << i + 1 << ": ";
				std::cin >> values[i];
			}
			for (int i = 0; i < NUM_VALUES10; i++) {
				int value = values[i];
				B.InsertNodes(value);
			}
		}
		system("cls");
		B.Print();
		B.setColor(15);
		B.gotoxy(0, 28);
		std::cout << "\nWould You Like A New Tree (y||n): ";
		std::cin >> choiceAgain;
		system("cls");
	} while (choiceAgain == 'y' || choiceAgain == 'Y');
	B.setColor(79);
	B.gotoxy(50, 14);
	std::cout << "====GOOD BYE====";
	while (1);
}






//int rootValue;
//std::cout << "Enter Your Root For The Tree: ";
//std::cin >> rootValue;
//if (rootValue > 25) {
//	std::cout << "\nMust Be Less Or Equal To 25: ";
//	std::cin >> rootValue;
//}
//system("cls");
// 
//B.SetRoot(rootValue, 55, 13);

// Right
//B.InsertNodes(30);
//B.InsertNodes(45);   // Comment To Check If Only Complete
//B.InsertNodes(25);
//B.InsertNodes(50);  // Comment To Check If Only Complete Or This To Check If Perfect
//B.InsertNodes(40); // Comment To Check If Only Complete Or This To Check If Perfect

// Left
//B.InsertNodes(12);
//B.InsertNodes(15);
//B.InsertNodes(10);