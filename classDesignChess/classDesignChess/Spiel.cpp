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

void Spiel::anzeigen(bool richtung)

{
	string key;
	char spalte;
	char zeile;
	
	dkremer::concolinit();
	dkremer::setcolor(green,black);
	// dkremer::setcolor(red, blue);
	std::cout << (richtung? "  ABCDEFGH ":"  HGFEDCBA ")<<"\n\n";
	for(zeile = '8'; zeile >= '1'; zeile--)
	{
		
		//std::cout<< (richtung ? zeile : '9' - zeile) << ' ';
		if (richtung)
			std::cout << zeile << ' ';
		else
			std::cout << ('9' - zeile) << ' ';
		for (spalte = 'a'; spalte <= 'h'; spalte++)
		{
			key = std::string(1, spalte) + zeile;

			std::cout << ((zeile + spalte) % 2 ? blue : red);
			std::cout << spielmap[key].get_figur().get_darstellung();

			// std::cout<<((zeile+spalte)%2?blue:red) << key << " ";
			// std::cout << spielmap[key].get_feldFarbe()<<" ";			
		}
		// std::cout <<' '<< (richtung ? zeile : '9' - zeile) << "\n";
		if (richtung)
			std::cout << ' ' << zeile << ' ' << "\n";
		else
			std::cout << ' ' << ('9' - zeile) << "\n";
	}
	dkremer::setcolor(green, black);
	std::cout <<"\n"<< (richtung ? "  ABCDEFGH " : "  HGFEDCBA ") << "\n";
	
}
