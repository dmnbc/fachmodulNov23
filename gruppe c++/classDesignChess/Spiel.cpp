
#include "Spiel.h"
#include "Feld.h"
#include "consolenfarbe.h"
#include <iostream>
#include <fstream>


using namespace dkremer;

Spiel::Spiel()
{
	// map füllen
	string key;
	char spalte;
	char zeile;

	for (int nr = 0; nr < 64; nr++)
	{
		spalte = 'a' + nr % 8;
		zeile = '1' + nr / 8;
		key = std::string(1, spalte) + zeile;
		spielmap[key] = Feld(key);
	}
	//std::cout << __LINE__ << ": spiel.cpp " << "ctor Spiel()\n";
}

void Spiel::anzeigen()
{
	if (richtung)
	{
		string key;
		char spalte;
		char zeile;


		dkremer::concolinit();
		dkremer::setcolor(green, black);
		// dkremer::setcolor(red, blue);
		std::cout << "    A B C D E F G H \n";

		for (zeile = '8'; zeile >= '1'; zeile--)
		{
			std::cout << zeile << " |";
			for (spalte = 'a'; spalte <= 'h'; spalte++)
			{
				key = std::string(1, spalte) + zeile;
				std::cout << ((zeile + spalte) % 2 ? blue : red) << " ";
				std::cout << spielmap[key].get_figur().get_darstellung();
			}

			std::cout << " | " << zeile << "\n";
		}
		std::cout << "    A B C D E F G H \n";
		dkremer::setcolor(green, black);
		richtung = false;
	}
	else
	{
		std::cout << "\n";

		string key;
		char spalte;
		char zeile;


		dkremer::concolinit();
		dkremer::setcolor(green, black);
		// dkremer::setcolor(red, blue);
		std::cout << "    H G F E D C B A \n";

		for (zeile = '1'; zeile <= '8'; zeile++)
		{
			std::cout << zeile << " |";
			for (spalte = 'h'; spalte >= 'a'; spalte--)
			{
				key = std::string(1, spalte) + zeile;
				std::cout << ((zeile + spalte) % 2 ? blue : red) << " ";
				std::cout << spielmap[key].get_figur().get_darstellung();
			}

			std::cout << " | " << zeile << "\n";
		}
		std::cout << "    H G F E D C B A \n";
		dkremer::setcolor(green, black);
		richtung = true;
	}
}
string Spiel::input()
{
	std::cin >> eingabe;
	while (sizeof(eingabe) != 4
		&& eingabeprüfung1.find(eingabe[1, 3]) != string::npos
		&& eingabeprüfung2.find(eingabe[2, 4]) != string::npos)
	{
		std::cin >> eingabe;
	}
	return eingabe;
}

// Wenn input "Speichern", wird diese Methode aufgerufen
void Spiel::speichern()
{
		ofstream speichern;
		speichern.open("Spielstand.txt");
		
		for (int i = 1; i < 2; i++)
		{
			if (richtung == true)
			{
				string key;
				char spalte;
				char zeile;


				dkremer::concolinit();
				dkremer::setcolor(green, black);
				// dkremer::setcolor(red, blue);
				speichern << "    A B C D E F G H \n";

				for (zeile = '8'; zeile >= '1'; zeile--)
				{
					speichern << zeile << " |";
					for (spalte = 'a'; spalte <= 'h'; spalte++)
					{
						key = std::string(1, spalte) + zeile;
						speichern << ((zeile + spalte) % 2 ? blue : red) << " ";
						speichern << spielmap[key].get_figur().get_darstellung();
					}

					speichern << " | " << zeile << "\n";
				}
				speichern << "    A B C D E F G H \n";
				dkremer::setcolor(green, black);
				richtung = false;
			
			
				speichern << "\n";
			
				//string key;
				//char spalte;
				//char zeile;


				dkremer::concolinit();
				dkremer::setcolor(green, black);
				// dkremer::setcolor(red, blue);
				speichern << "    H G F E D C B A \n";

				for (zeile = '1'; zeile <= '8'; zeile++)
				{
					speichern << zeile << " |";
					for (spalte = 'h'; spalte >= 'a'; spalte--)
					{
						key = std::string(1, spalte) + zeile;
						speichern << ((zeile + spalte) % 2 ? blue : red) << " ";
						speichern << spielmap[key].get_figur().get_darstellung();
					}

					speichern << " | " << zeile << "\n";
			
				}
			}
				speichern << "    H G F E D C B A \n";
				dkremer::setcolor(green, black);
				richtung = true;
			}
}


// Wenn input "Laden", wird diese Methode aufgerufen
void Spiel::laden()
{
	ofstream load("Spielstand.txt", ios::out);
}