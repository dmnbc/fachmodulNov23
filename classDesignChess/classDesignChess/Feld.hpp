#pragma once

#include "Figur.hpp"
#include <vector>
#include <string>
class Feld
{
public:
	char spalte{' '};
	char zeile {' '};
	int  laufendeFeldnummer{ 0 };
	bool hell{ true };
	Figur* figur;      // Zeiger auf Figur! deshalb mit new zu bilden 
    std::vector<std::string> erlaubteZiele; 


	Feld();
	Feld(char, char); 

};

