#include "Pferd.h"
#include <iostream>

Pferd::Pferd()
{
	std::cout << __LINE__ << ":" << __FILE__ << "ctor Pferd()\n";
}

Pferd::Pferd(char Fig)
{
	if (Fig == 'p') {
		darstellung = 'p';
	}
	else
		darstellung = 'P';
}