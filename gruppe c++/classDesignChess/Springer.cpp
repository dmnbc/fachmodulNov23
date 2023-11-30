#include "Springer.h"
#include <iostream>

Springer::Springer()
{
	std::cout << __LINE__ << ":" << __FILE__ << "ctor Springer()\n";
}

Springer::Springer(char Fig)
{
	Fig - 'A' >= 0 ? std::cout << "p" : std::cout << "P";
}
