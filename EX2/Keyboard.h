#pragma once
#include "Settings.h"

namespace Keyboard
{
	// Implements the same semantics as _getch() from conio.h
	// Currently, handles only regular keys (ASCII values)
	// and arrow keys
	int getch();
};

