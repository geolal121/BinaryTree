#include "Connect.h"
#include "Coordinates.h"

void Connect::Link(int x1, int y1, int x2, int y2) {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//If Object Is Right Bottom
	if (x2 > x1 && y2 > y1) {
		gotoxy(x1, y1);
		std::cout << char(179);
		gotoxy(x1, y1 + 1);
		std::cout << char(192);
		for (int i = x1 + 1; i < x2; i++) {
			gotoxy(i, y1 + 1);
			std::cout << char(196);
		}
		gotoxy(x2, y1 + 1);
		std::cout << char(191);
		for (int i = y1 + 2; i < y2; i++) {
			gotoxy(x2, i);
			std::cout << char(179);
		}
	}
	// If Object Is Right Top
	else if (x2 > x1 && y2 < y1) {
		gotoxy(x1, y1);
		std::cout << char(179);
		gotoxy(x1, y1 + 1);
		std::cout << char(192);
		for (int i = x1 + 1; i < x2; i++) {
			gotoxy(i, y1 + 1);
			std::cout << char(196);
		}
		gotoxy(x2, y1 + 1);
		std::cout << char(217);
		for (int i = y1; i > y2; i--) {
			gotoxy(x2, i);
			std::cout << char(179);
		}
	}
	// If Object Is Left Bottom
	else if (x2 < x1 && y2 > y1) {
		gotoxy(x1, y1);
		std::cout << char(179);
		gotoxy(x1, y1 + 1);
		std::cout << char(217);
		for (int i = x1 - 1; i > x2; i--) {
			gotoxy(i, y1 + 1);
			std::cout << char(196);
		}
		gotoxy(x2, y1 + 1);
		std::cout << char(218);
		for (int i = y1 + 2; i < y2; i++) {
			gotoxy(x2, i);
			std::cout << char(179);
		}
	}
	// If Object Is Left Top
	else if (x2 < x1&& y2 < y1) {
		gotoxy(x1, y1);
		std::cout << char(179);
		gotoxy(x1, y1 + 1);
		std::cout << char(217);
		for (int i = x1 - 1; i > x2; i--) {
			gotoxy(i, y1 + 1);
			std::cout << char(196);
		}
		gotoxy(x2, y1 + 1);
		std::cout << char(192);
		for (int i = y1; i > y2; i--) {
			gotoxy(x2, i);
			std::cout << char(179);
		}
	}
}