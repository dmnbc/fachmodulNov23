#include "Bauer.h"
#include <iostream>

Bauer::Bauer()
{
	std::cout << __LINE__ << ":" << __FILE__ << "ctor Bauer()\n";
}

Bauer::Bauer(char Fig)
{
	if (Fig == 'b') {
		darstellung = 'b';
	}
	else
		darstellung = 'B';
}
