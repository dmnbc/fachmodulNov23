#include "Laeufer.h"
#include <iostream>

Laeufer::Laeufer()
{
	std::cout << __LINE__ << ":" << __FILE__ << "ctor Laeufer()\n";
}

Laeufer::Laeufer(char Fig)
{
	if (Fig == 'l') {
		darstellung = 'l';
	}
	else
		darstellung = 'L';
}