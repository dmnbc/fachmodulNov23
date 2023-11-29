// OOP_Schach_Projekt.cpp : 



#include <iostream>
#include <string>
#include <locale>

#include "Spiel.hpp"
#include <Windows.h>

std::map<std::string, Feld> Spiel::spielStand;
std::ofstream Spiel::ausgabeStrom; // noch ohne Dateinamen und Anfüge-modus

std::ofstream history;



int main()
{
	setlocale(LC_ALL, "de_DE");

	history.open("./ohistory.txt"); // jedes Spiel überschreibt die Datei


	//---------------------  Grundstellung aufbauen --------
	Spiel s; // in Grundstellung durch Aufruf des ctors
	         // darin erzeugen der map aus Feldern mit den Schlüsseln gemäß Koordinaten
	         // Füllen der Felder mit Figuren 
	         // auch den Namen der Protokolldatei erfragen
	//Spiel::ausgabeStrom.open(s.protokollDatei, std::ios::app); // ausgabeStrom öffnen 
   	std::cout << s << std::endl; // zeigt alle Inhalte der 64 Felder
    s.darstellen();           // zeichnet Schachbrett mit Spielstand
	// 
	//---------------------  Spielen -----------------------
	do
	{
		s.ziehen(); 
		std::cout << s << std::endl;
	    s.darstellen();

		history << s; 
		/* einfache Protokolldatei schreiben
		history << s.get_zugNumer() << std::endl;
		for (char zeile = '1'; zeile <= '8'; zeile++)
		{
			for (char spalte = 'A'; spalte <= 'H'; spalte++)
			{
				std::string f = s.get_spielStand()[{spalte, zeile}].figur->get_figurTyp();
				history << (f == "Leer"?" ":f);
			}
			history << std::endl;
		}*/
	} while (true); 
	
}
