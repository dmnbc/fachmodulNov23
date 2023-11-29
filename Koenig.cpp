#include "Koenig.h"
#include <iostream>

Koenig::Koenig()
{
	std::cout << __LINE__ << ":" << __FILE__ << "ctor Koenig()\n";
}

Koenig::Koenig(char Fig)
{
	if (Fig == 'k') {
		darstellung = 'k';
	}
	else
		darstellung = 'K';
}
