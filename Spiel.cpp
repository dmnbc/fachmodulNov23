#include "Spiel.h"
#include "Feld.h"
#include "consolenfarbe.h"

using namespace dkremer;

void setCursorPosition(unsigned int x, unsigned int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

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
	//setCursorPosition(20, 20);
	ofile.open("gameshistorie.txt", std::ios::app);
	string key;
	char spalte;
	char zeile;
	char zeilestart = (richtung ? '1' : '8');
	char zeileende = (richtung ? '9' : '0');
	char spaltestart = (richtung ? 'h' : 'a');
	char spalteende = (richtung ? 'a' : 'i');
	int  step = (richtung ? 1 : -1);
	
	dkremer::concolinit();
	dkremer::setcolor(green,black);
	// dkremer::setcolor(red, blue);
	std::cout << (richtung? "  ABCDEFGH ":"  HGFEDCBA ")<<"\n\n";	
	ofile << (richtung ? "  ABCDEFGH " : "  HGFEDCBA ") << "\n\n";
	for (zeile = zeilestart; zeile != zeileende; zeile += step)
	{
		std::cout << zeile << ' ';
		ofile << zeile << ' ';
		for (spalte = spaltestart; spalte != spalteende; spalte -= step)
		{
			key = std::string(1, spalte) + zeile;
			std::cout << ((zeile + spalte) % 2 ? blue : red);
			std::cout << spielmap[key].get_figur().get_darstellung();	
			ofile<< spielmap[key].get_figur().get_darstellung();
		}	
		std::cout << ' ' << zeile << ' ' << "\n";	
		ofile<< "\n";
	}
	dkremer::setcolor(green, black);
	std::cout <<"\n"<< (richtung ? "  ABCDEFGH " : "  HGFEDCBA ") << "\n";
	ofile.close();
}
