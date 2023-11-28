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


void Spiel::anzeigen()
/*{
 // alle Felder mit ihrer feldFarbe als Quadrat darstellen

	for( auto zeile : spielfeld)
	{
		for (auto feld : zeile)
		{
			std::cout << feld.get_feldFarbe();
		}
		std::cout << "\n";
	}
}*/
{
	string key;
	char spalte;
	char zeile;
	
	for(zeile = '8'; zeile >= '1'; zeile--)
	{
		for (spalte = 'a'; spalte <= 'h'; spalte++)
		{
			key = std::string(1, spalte) + zeile;
			std::cout << key << " ";
			std::cout << spielmap[key].get_feldFarbe()<<" ";			
		}
		std::cout <<  "\n" ;
	}
}
