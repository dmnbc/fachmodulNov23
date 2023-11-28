#pragma once

#include <iostream>
#include <iomanip>
#include <map>
#include <array>
#include <string>
#include "Feld.hpp"
#include <fstream>



class Spiel
{
	std::array<std::string, 2> spielerName{ "sp1","sp2" };
	int zugNumer{ 0 };	

	friend std::ostream& operator<< (std::ostream& os, Spiel const& s)
	{
     
	  for (auto f : s.spielStand)
		{
		  if (f.second.figur->get_figurTyp()!="Leer")
		  {
			  os << f.first << " " << f.second.hell << " "
				  << std::setw(6) << std::left << f.second.figur->get_figurTyp()
				  << f.second.figur->get_figurFarbe() << " ";
			  os << " -->";
			  for (std::string ef : f.second.erlaubteZiele)
			  {
				  os << ef << ',';
			  }
			  os << std::endl;
		  }
		}
		return os; 
	}


public:
	Spiel();
	std::map<std::string, Feld> get_spielStand() { return spielStand; }
	//void ziehen(std::string, std::string);
	static std::string getTypeIn(std::string); 
	static std::map<std::string, Feld> spielStand; // z.B  spielstand["A2"] enthält einen dunklen Bauern....
	void darstellen();
	void ziehen(); // Abfrage der Zug-Koordinaten, Bewegen des Feldinhalt von -> nach
	static std::map<std::string, Feld> bedrohteFelder; // Teilmenge der erlaubten Felder, die nicht leer sind

	std::string protokollDatei;          // der Dateiname sollte in ctor festgelegt werden 
	static std::ofstream ausgabeStrom;   // muss in der ganzen Anwendung verfügbar sein
	        //         bewegt      von          nach     schlägt  wen 
	void protokollieren(Figur, std::string, std::string, bool, Figur); // soll den Zug in eine Datei schreiben
	int get_zugNumer() { return zugNumer; }
};



