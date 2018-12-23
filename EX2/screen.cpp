#include "screen.h"

#include <Windows.h>

void moveCursor(const Position & pos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)pos.col, (short)pos.row });
}
