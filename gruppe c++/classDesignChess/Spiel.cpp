#include "Spiel.h"
#include "Feld.h"
#include "consolenfarbe.h"
#include "Leer.h"
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace dkremer;

Spiel::Spiel()																						//Initiierung des Spiels
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
/*{																									//alte Darstellung mit feldFarbe
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
	{																								//Ausgabe
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
	{																								//gedrehte Ausgabe
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
	std::string zielpunkt2;																			//erste Eingabeaufforderung
	std::cin >> eingabe;
	zwischenspeicher = eingabe;
	std::cout << "\n";
	eingabe[0] = tolower(eingabe[0]);
	eingabe[2] = tolower(eingabe[2]);
	zielpunkt2 = eingabe.substr(2, 2);


	while (!std::any_of(zugliste.begin(), zugliste.end(), [zielpunkt2](std::string prüfer) {return prüfer == zielpunkt2; })) //wiederholt Eingabeaufforderung solange, bis korrekte Angabe (in Liste zugliste enthalten)
	{
		std::cout << "Kein regelkonformer Zug, bitte erneut eingeben!\n\n";
		std::cin >> eingabe;
		zwischenspeicher = eingabe;
		std::cout << "\n";
		eingabe[0] = tolower(eingabe[0]);
		eingabe[2] = tolower(eingabe[2]);
		zielpunkt2 = eingabe.substr(2, 2);
	}

	/*while (eingabe.length() != 4																	//Regelprüfung, redundant, sobald Liste aller möglichen Züge implementiert
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

		//system("CLS");																			// Clear Screen

	zwischenspeicher[0] = toupper(zwischenspeicher[0]);
	zwischenspeicher[2] = toupper(zwischenspeicher[2]);
	std::cout << "\nLetzer Zug:" << zwischenspeicher << " (" << eingabe << ")\n\n";
	return eingabe;
}

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


// Wenn input "Laden", wird diese Methode aufgerufen												//nicht implementierte Methode
void Spiel::laden()
{
	spielmap = speicherstand;
	// Spiel wird fortgesetzt durch Verweis auf Spielzugmethodik
}


void Spiel::ziehen()
{
	startpunkt = eingabe.substr(0, 2);
	zielpunkt = eingabe.substr(2, 2);

	/*std::cout << "Spielmap davor:\nStartpunkt(" << startpunkt << "): "							//Tests
		<< spielmap[startpunkt].get_figur().get_darstellung() << "\nZielpunkt(" << zielpunkt
		<< "): " << spielmap[zielpunkt].get_figur().get_darstellung() << "\n\n";
	std::cout << "Feld davor:\nStartpunkt(" << startpunkt << "): "
		<< Feld(startpunkt).get_figur().get_darstellung() << "\nZielpunkt(" << zielpunkt
		<< "): " << Feld(zielpunkt).get_figur().get_darstellung() << "\n\n";*/

	spielmap[zielpunkt] = Feld(startpunkt);															//Fehlerhaft, da nach dem ersten ziehen die Map beeinflusst wird, aber beim zweiten Aufruf Feld(startpunkt) noch immer die Figur der Grundaufstellung beinhaltet und nicht verändert wurde.

	/*std::cout << "Spielmap Mittendrin:\nStartpunkt(" << startpunkt << "): "						//Tests
			<< spielmap[startpunkt].get_figur().get_darstellung() << "\nZielpunkt(" << zielpunkt
			<< "): " << spielmap[zielpunkt].get_figur().get_darstellung() << "\n\n";
	std::cout << "Feld Mittendrin:\nStartpunkt(" << startpunkt << "): "
		<< Feld(startpunkt).get_figur().get_darstellung() << "\nZielpunkt(" << zielpunkt
		<< "): " << Feld(zielpunkt).get_figur().get_darstellung() << "\n\n";*/

	spielmap[startpunkt] = Feld(zielpunkt);															//Fehlerhaft, siehe oben

	Feld temp;																						//Versuch, den Fehler zu beheben (Leider Nein)
	temp.get_figur() = Feld(startpunkt).get_figur();
	Feld(startpunkt).get_figur() = Feld(zielpunkt).get_figur();
	Feld(zielpunkt).get_figur() = temp.get_figur();

	/*std::cout << "Spielmap danach:\nStartpunkt(" << startpunkt << "): "							//Tests
		<< spielmap[startpunkt].get_figur().get_darstellung() << "\nZielpunkt(" << zielpunkt
		<< "): " << spielmap[zielpunkt].get_figur().get_darstellung() << "\n\n";
	std::cout << "Feld danach:\nStartpunkt(" << startpunkt << "): "
		<< Feld(startpunkt).get_figur().get_darstellung() << "\nZielpunkt(" << zielpunkt
		<< "): " << Feld(zielpunkt).get_figur().get_darstellung() << "\n\n";*/

}