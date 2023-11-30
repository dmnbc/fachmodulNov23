#include "Koenigin.h"
#include <iostream>

Koenigin::Koenigin()
{
	std::cout << __LINE__ << ":" << __FILE__ << "ctor Koenigin()\n";
}

Koenigin::Koenigin(char Fig)
{
	Fig - 'A' >= 0 ? std::cout << "d" : std::cout << "D";
}
