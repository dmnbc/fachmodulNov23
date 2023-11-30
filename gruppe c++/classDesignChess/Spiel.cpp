#include "Spiel.h"
#include "Feld.h"
#include "consolenfarbe.h"
#include "Leer.h"

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
	if (richtung)
	{
		std::cout << "Spieler Weiss ist am Zug!\n\n";

		string key;
		char spalte;
		char zeile;


		dkremer::concolinit();
		//dkremer::setcolor(green, black);
		// dkremer::setcolor(red, blue);
		std::cout << "    A B C D E F G H \n";
		std::cout << "    --------------- \n";

		for (zeile = '8'; zeile >= '1'; zeile--)
		{
			std::cout << zeile << " |";
			for (spalte = 'a'; spalte <= 'h'; spalte++)
			{
				key = std::string(1, spalte) + zeile;
				std::cout << ((zeile + spalte) % 2 ? blue : red) << " ";
				std::cout << spielmap[key].get_figur().get_darstellung();
				std::cout << white;
			}

			std::cout << " | " << zeile << "\n";
		}
		std::cout << "    --------------- \n";
		std::cout << "    A B C D E F G H \n";
		//dkremer::setcolor(green, black);
		richtung = false;
	}
	else
	{
		std::cout << "Spieler Schwarz ist am Zug!\n\n";

		string key;
		char spalte;
		char zeile;


		dkremer::concolinit();
		//dkremer::setcolor(green, black);
		// dkremer::setcolor(red, blue);
		std::cout << "    H G F E D C B A \n";
		std::cout << "    --------------- \n";

		for (zeile = '1'; zeile <= '8'; zeile++)
		{
			std::cout << zeile << " |";
			for (spalte = 'h'; spalte >= 'a'; spalte--)
			{
				key = std::string(1, spalte) + zeile;
				std::cout << ((zeile + spalte) % 2 ? blue : red) << " ";
				std::cout << spielmap[key].get_figur().get_darstellung();
				std::cout << white;
			}

			std::cout << " | " << zeile << "\n";
		}
		std::cout << "    --------------- \n";
		std::cout << "    H G F E D C B A \n";
		//dkremer::setcolor(green, black);
		richtung = true;
	}
}
string Spiel::input()
{
	std::cin >> eingabe;
	std::cout << "\n";
	eingabe[0] = tolower(eingabe[0]);
	eingabe[2] = tolower(eingabe[2]);
	//std::cout << eingabe[0] << eingabe[1] << eingabe[2] << eingabe[3] << " " << eingabe.length() << "\n"; //Tests
	//eingabeprüfung1.find(eingabe[0]) == string::npos ? std::cout << "Ja\n" : std::cout << "Nein\n";
	//eingabeprüfung2.find(eingabe[1]) == string::npos ? std::cout << "Ja\n" : std::cout << "Nein\n";
	//eingabeprüfung1.find(eingabe[2]) == string::npos ? std::cout << "Ja\n" : std::cout << "Nein\n";
	//eingabeprüfung2.find(eingabe[3]) == string::npos ? std::cout << "Ja\n" : std::cout << "Nein\n";
	while (eingabe.length() != 4
		|| eingabeprüfung1.find(eingabe[0]) == string::npos
		|| eingabeprüfung2.find(eingabe[1]) == string::npos
		|| eingabeprüfung1.find(eingabe[2]) == string::npos
		|| eingabeprüfung2.find(eingabe[3]) == string::npos
		|| (eingabe[0] == eingabe[2] && eingabe[1] == eingabe[3]))
		//|| (eingabe[1] == eingabe[3] && (eingabe[0] + 32) == eingabe[2]) //Nur, wenn kein toupper() für Eingabe vorhanden
		//|| (eingabe[1] == eingabe[3] && eingabe[0] == (eingabe[2] + 32))) // "
	{
		std::cout << "Falsche Eingabe! Bitte zwei zusammenhängenden Koordinaten von A1-A8 eingeben,\ndie nicht identisch sind. (Beispiel: B2C3 || Ihre Eingabe:" << eingabe << ")\n";
		std::cin >> eingabe;
	}
	return eingabe;
}

// Wenn input "Speichern", wird diese Methode aufgerufen
void Spiel::speichern()
{
	speicherstand = spielmap;
}

// Wenn input "Laden", wird diese Methode aufgerufen
void Spiel::laden()
{
	spielmap = speicherstand;
	// Spiel wird fortgesetzt durch Verweis auf Spielzugmethodik
}


void Spiel::ziehen()
{
	/*startpunkt_s = eingabe.substr(0);
	startpunkt_z = eingabe.substr(1);
	zielpunkt_s = eingabe.substr(2);
	zielpunkt_z = eingabe.substr(3);
	//std::cout << startpunkt << " " << zielpunkt;*/
	startpunkt = eingabe.substr(0, 2);
	zielpunkt = eingabe.substr(2, 2);
	spielmap[zielpunkt] = Feld(startpunkt);
	spielmap[startpunkt] = Feld(zielpunkt);
	//spielmap[zielpunkt].get_figur() = Feld(startpunkt).get_figur();
	//spielmap[startpunkt].get_figur() = Feld(zielpunkt).get_figur();
	//std::cout << startpunkt << spielmap[startpunkt].get_figur().get_darstellung();
	//std::cout << zielpunkt << spielmap[zielpunkt].get_figur().get_darstellung();
	//Feld(startpunkt).get_figur;
	//std::cout << spielmap[startpunkt].get_figur()
}