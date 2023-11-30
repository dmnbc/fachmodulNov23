#pragma once

#include <array>
#include <map>    // aus STL 
#include <string>

#include "Feld.h"

using namespace std;

class Spiel
{
private:
	// das spielfeld hat 64 Felder testy testy
	//array<array<Feld, 8>, 8> spielfeld;
	map<string, Feld> spielmap;
	map<string, Feld> speicherstand;
	bool richtung = true;
	std::string eingabe;
	string zwischenspeicher; // um genaue eingabe wiederzugeben
	string eingabeprüfung1 = "ABCDEFGHabcdefgh";
	string eingabeprüfung2 = "12345678";
	string startpunkt, startpunkt_s, startpunkt_z;
	string zielpunkt, zielpunkt_s, zielpunkt_z;
	std::array <std::string, 2> zugliste { "a3", "a4" };
	//int zuganzahl;
	//string spielhistorie[];
	std::string zeilpunkt2;

public:
	Spiel();

	void anzeigen();
	void speichern();
	void laden();
	void ziehen();
//	string zugliste();
	string input();


};
