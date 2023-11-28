#include "Spiel.h"
#include "Feld.h"

Spiel::Spiel()
{
	// map füllen
	string key;
	char spalte;
	char zeile;
	for (char spalte = 'a'; spalte <= 'h'; spalte++)
	{
		for (char zeile = '1'; zeile <= '8'; zeile++)
		{
			key = std::string(1, spalte) + zeile;
			spielmap[key] = Feld(key);
		}

	}



	std::cout << __LINE__ << ": spiel.cpp " << "ctor Spiel()\n";
}


void Spiel::anzeigen(bool richtung)

{
	string key;
	char spalte;
	char zeile;
	std::cout << (richtung ? "  H G F E D C B A  " : "  A B C D E F G H  ") << "\n"; 
	for (zeile = '8'; zeile >= '1'; zeile--)
	{
		if (richtung)
			std::cout << zeile << ' ';
		else
			std::cout << ('9' - zeile) << ' ';
		for (spalte = 'A'; spalte <= 'H'; spalte++)
		{
			key = Feld(std::string(1, spalte) + zeile);
			std::cout << spielmap[key].get_feldFarbe() << " ";
		}
		std::cout << "\n";
	}
};