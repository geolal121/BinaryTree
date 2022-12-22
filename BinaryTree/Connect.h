#pragma once
#include "Coordinates.h"

class Connect : public Coordinates {
public:
	HANDLE hConsole;
	void Link(int xOne, int yOne, int xTwo, int yTwo);
};