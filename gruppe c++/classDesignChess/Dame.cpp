#include "Dame.h"
#include <iostream>

Dame::Dame()
{
	std::cout << __LINE__ << ":" << __FILE__ << "ctor Koenigin()\n";
}

Dame::Dame(char Fig)
{
	if (Fig == 'd') {
		std::cout << 'd';
	}
	else
		std::cout << 'D';
}
