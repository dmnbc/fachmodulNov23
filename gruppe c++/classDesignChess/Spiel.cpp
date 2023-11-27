#include "Spiel.h"
#include "Feld.h"
#include "consolenfarbe.h"

using namespace dkremer;

Spiel::Spiel()
{
	// map füllen
	string key;
	char spalte;
	char zeile;
	for( int nr = 0; nr < 64; nr++)
	{
		spalte = 'a' + nr % 8; 
		zeile  = '1' + nr / 8;
		key = std::string(1, spalte) + zeile;
		spielmap[key] = Feld(key);
	}
	//std::cout << __LINE__ << ": spiel.cpp " << "ctor Spiel()\n";
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
	
	dkremer::concolinit();
	dkremer::setcolor(green,black);
	// dkremer::setcolor(red, blue);
	for(zeile = '8'; zeile >= '1'; zeile--)
	{
		for (spalte = 'a'; spalte <= 'h'; spalte++)
		{
			key = std::string(1, spalte) + zeile;
			std::cout<<((zeile+spalte)%2?blue:red) << key << " ";
			// std::cout << spielmap[key].get_feldFarbe()<<" ";			
		}
		std::cout <<  "\n" ;
	}
	dkremer::setcolor(green,black);
}
