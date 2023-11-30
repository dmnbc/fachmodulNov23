#include <iostream>
#include <fstream>
#include "Spiel.h"
#include "Feld.h"
#include "consolenfarbe.h"
#include "Leer.h"
#include <algorithm>

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
		std::cout << "    A B C D E F G H \n\n";
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
		std::cout << "    H G F E D C B A \n\n";
		//dkremer::setcolor(green, black);
		richtung = true;
	}
}
string Spiel::input()
{
	std::string zielpunkt2;
	std::cin >> eingabe;
	zwischenspeicher = eingabe;
	std::cout << "\n";
	eingabe[0] = tolower(eingabe[0]);
	eingabe[2] = tolower(eingabe[2]);
	zielpunkt2 = eingabe.substr(2, 2);


	while (!std::any_of(zugliste.begin(), zugliste.end(), [zielpunkt2](std::string prüfer) {return prüfer == zielpunkt2; }))
	{
		std::cout << "Kein regelkonformer Zug, bitte erneut eingeben!";
		std::cin >> eingabe;
		zwischenspeicher = eingabe;
		std::cout << "\n";
		eingabe[0] = tolower(eingabe[0]);
		eingabe[2] = tolower(eingabe[2]);
		startpunkt = eingabe.substr(0, 2);
		zielpunkt = eingabe.substr(2, 2);
	}

	/*while (eingabe.length() != 4
		|| eingabeprüfung1.find(eingabe[0]) == string::npos
		|| eingabeprüfung2.find(eingabe[1]) == string::npos
		|| eingabeprüfung1.find(eingabe[2]) == string::npos
		|| eingabeprüfung2.find(eingabe[3]) == string::npos
		|| (eingabe[0] == eingabe[2] && eingabe[1] == eingabe[3]))
		//|| erlaubt == true)
		//zugliste != std::find(std::begin(eingabe), std::end(eingabe), zielpunkt)); // Versuch 1 Listenabgleich
		//|| (eingabe[1] == eingabe[3] && (eingabe[0] + 32) == eingabe[2]) //Nur, wenn kein toupper() für Eingabe vorhanden
		//|| (eingabe[1] == eingabe[3] && eingabe[0] == (eingabe[2] + 32))) // "
	 {
		std::cout << "Falsche Eingabe! Bitte zwei zusammenhängenden Koordinaten von A1-A8 eingeben,\ndie nicht identisch sind. (Beispiel: B2C3 oder b2c3 || Ihre Eingabe:"
			<< zwischenspeicher << ")\n";
		std::cin >> eingabe;
	}*/

	//}

		//liste erlaubtes feld und erreichen, dass nur diese felder angesprochen werden können
		//system("CLS"); // Clear Screen
		//zuganzahl++;
		//spielhistorie[zuganzahl] = eingabe;
		/*std::cout << "Liste aller bisherigen Zuege:\n";  // Versuch einer Spielhistorie
		for (int i = 1; i < zuganzahl+1; i++)
		{
			std::cout << "Zug " << zuganzahl << ": " << spielhistorie[i] << "\n";
		}*/
	zwischenspeicher[0] = toupper(zwischenspeicher[0]);
	zwischenspeicher[2] = toupper(zwischenspeicher[2]);
	std::cout << "\nLetzer Zug:" << zwischenspeicher << "\n\n";
	return eingabe;
}

// Wenn input "Speichern", wird diese Methode aufgerufen

void Spiel::speichern()
{
	ofstream speichern;
	speichern.open("Spielstand.txt");

	for (int i = 1; i < 2; i++)
	{
		string key;
		char spalte;
		char zeile;

		speichern << "    A B C D E F G H \n";

		for (zeile = '8'; zeile >= '1'; zeile--)
		{
			speichern << zeile << " |";
			for (spalte = 'a'; spalte <= 'h'; spalte++)
			{
				key = std::string(1, spalte) + zeile;
				speichern << ((zeile + spalte) % 2 ? blue : red) << " ";
				speichern << spielmap[key].get_figur().get_darstellung();
				std::cout << white;
			}
			speichern << " | " << zeile << "\n";
		}
		speichern << "    A B C D E F G H \n";
		
		richtung = false;

		speichern << "\n";
		speichern << "    H G F E D C B A \n";

		for (zeile = '1'; zeile <= '8'; zeile++)
		{
			speichern << zeile << " |";
			for (spalte = 'h'; spalte >= 'a'; spalte--)
			{
				key = std::string(1, spalte) + zeile;
				speichern << ((zeile + spalte) % 2 ? blue : red) << " ";
				speichern << spielmap[key].get_figur().get_darstellung();
				std::cout << white;
			}
			speichern << " | " << zeile << "\n";

		}
		speichern << "    H G F E D C B A \n";
		richtung = true;
	}
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
	zielpunkt_z = eingabe.substr(3);*/

	//std::cout << startpunkt << " " << zielpunkt;
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

//string Spiel::zugliste()
//{

//}


