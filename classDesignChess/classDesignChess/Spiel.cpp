#include "Spiel.hpp"
#include "Leer.hpp"
#include <iostream>
#include <algorithm>
#include "consolenfarbe.h"
#include <fstream>

void setCursorPosition(unsigned int x, unsigned int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}


void Spiel::darstellen()
{
	unsigned int startzeile { 10 };
	unsigned int startspalte{ 50 };
	setCursorPosition(startspalte,startzeile);
	farbe::concolinit();
	for (char z = '1'; z <= '8'; z++)
	{
		for (char s = 'A'; s <= 'H'; s++)
		{
			std::string feld{ s,z };
			if ((z + s) % 2)
			{
				if (this->spielStand[feld].figur->get_figurFarbe())
				{
					farbe::setcolor(farbe::concol::black, farbe::concol::dark_blue);
				}
				else
				{
					farbe::setcolor(farbe::concol::red, farbe::concol::dark_blue);
				}
			}
			else
			{
				if (this->spielStand[feld].figur->get_figurFarbe())
				{
					farbe::setcolor(farbe::concol::black, farbe::concol::white);
				}
				else
				{
					farbe::setcolor(farbe::concol::red, farbe::concol::white);
				}

			}
			
			
			std::cout << (this->spielStand[feld].figur->get_figurTyp() == "Leer" ? " " : this->spielStand[feld].figur->get_figurTyp());

		
		}
		farbe::setcolor(farbe::concol::black, farbe::concol::black);
		
		 setCursorPosition(startspalte,++startzeile);
		// std::cout << std::endl;
	}
	farbe::setcolor(farbe::concol::red, farbe::concol::black);
}

Spiel::Spiel()
{
	// Grundaufstellung 
	for (char spalte = 'A'; spalte <= 'H'; spalte++)
	{
		for (char zeile = '1'; zeile <= '8'; zeile++)
		{
			std::string key{ spalte,zeile }; // bildet die strings A1, A2 usw. bis H7, H8
			spielStand[key]  = Feld(spalte,zeile); // besetzt die map mit den Figuren und Feldern
			//    z.B ["A2"] = Feld-Objekt ( 'A', '2' ); -> ctor Feld
		}
	}

	// Vorbereiten der Protokolldatei
	//std::cout << "Bitte geben Sie den Namen der Datei an : ";
	//std::cin >> protokollDatei;	 
	

}

// void Spiel::ziehen(std::string eingabeVon, std::string eingabeNach)
   void Spiel::ziehen()
{
	   farbe::settextcolor(farbe::concol::white); 
	   setCursorPosition(40, 6);

	   std::cout << "Bitte eine Figur auswählen : ";
	   std::string eingabeVon;
	   std::cin >> eingabeVon;

	   setCursorPosition(40, 8);

	   std::cout << "Bitte ein Ziel   auswählen : ";
	   std::string eingabeNach;
	   std::cin >> eingabeNach;

	system("CLS"); 
	int AnzahlErlaubteZiele = get_spielStand()[eingabeVon].erlaubteZiele.size();

	if (AnzahlErlaubteZiele) // != 0 bedeutet, dass es erlaubte Felder gibt
	{  /*
		std::cout << eingabeVon << " ist ein " << spielStand[eingabeVon].figur->get_figurTyp() << std::endl;
		std::cout << AnzahlErlaubteZiele << " erlaubte Zielfelder wären ";
		for (int i = 0; i < AnzahlErlaubteZiele; i++)
		{
			std::cout << spielStand[eingabeVon].erlaubteZiele.at(i) << ' ';
		}
		std::cout << std::endl;*/
		// ist eingabeNach ein erlaubtes Feld ? 
		// siehe https://www.cplusplus.com/reference/algorithm/any_of/
		if (std::any_of(spielStand[eingabeVon].erlaubteZiele.begin(), // first
			            spielStand[eingabeVon].erlaubteZiele.end(),   // last
			            [eingabeNach](std::string s)                  // Predicate
			{return s == eingabeNach; }))
			// Für jedes Element der map erlaubteZiele wird geprüft ob dieses
			// mit dem Wert von eingabeNach übereinstimmt. Ist wenigstens eine
			// Übereinstimmung gegeben, wird nach Abarbeiten der Liste  true an das if
			// gegeben. Ohne eine Übereinstimmung wird das if in den false-Zweig gehen
			{   // ja, Zug ist erlaubt
				std::cout << "Zug ist erlaubt\n";
				// Figur bewegen 
				bool geschlagen = (spielStand[eingabeNach].figur->get_figurFarbe() 
					             != spielStand[eingabeVon].figur->get_figurFarbe()
					             && (spielStand[eingabeNach].figur->get_figurTyp() != "Leer"));

				
			
				//protokollieren(*spielStand[eingabeVon].figur, eingabeVon, eingabeNach, 
				//	            geschlagen, *spielStand[eingabeNach].figur);

				spielStand[eingabeNach].figur = spielStand[eingabeVon].figur; // an neue Position

				spielStand[eingabeVon].figur = new Leer("Leer",true); // an alter Position  ->typ = "Leer"; // ?? 
				spielStand[eingabeVon].erlaubteZiele.clear(); // Liste zurücksetzen

				// Nach der Bewegung einer Figur können sich die Möglichkeiten 
				// aller anderen Figuren ändern
				// daher Neuberechnung aller erlaubten Felder 
				// für alle Figuren  mit  polymorphem Aufruf der Regeln,
				// je nach Typ der Figur
				
				// Alle Felder aufsuchen
				for (char spalte = 'A'; spalte <= 'H'; spalte++)
				{
					for (char zeile = '1'; zeile <= '8'; zeile++)
					{
						std::string key{ spalte,zeile };
						// Neuberechnen der erlaubten Felder                  polymorph
						spielStand[key].erlaubteZiele = spielStand[key].figur->erlaubteFelderErrechnen(key);

					}
				}
			}
			else
			{
				std::cout << "Zug ist nicht erlaubt\n";
			}		
	}
	else
	{
		std::cout << "Vom Feld " << eingabeVon << " kann kein Zug ausgehen \n";
	}
	zugNumer++;

}

   void Spiel::protokollieren(Figur f, std::string von , std::string nach , bool schlagen , Figur wen)
   {
	   //  in Datei schreiben.

	   Spiel::ausgabeStrom << f.get_figurTyp() << " von " << von << " nach " << nach 
		   << (schlagen ? " ersetzt "+wen.get_figurTyp():" ")
		   << std::endl;


   }

std::string Spiel::getTypeIn(std::string f)
{

	return "Leer"; // TODO:  typ der Figur eines Feldes f
}
