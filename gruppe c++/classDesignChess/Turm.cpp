#include "Turm.h"
#include <iostream>

Turm::Turm()
{
	// std::cout << __LINE__ << ":" << __FILE__ << "ctor Turm()\n";
}

Turm::Turm(char Fig)
{
	if (Fig == 't') {
		darstellung = 't';
	}
	else
		darstellung = 'T';
}
