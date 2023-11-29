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
	string eingabe;
	string eingabepr�fung1 = "ABCDEFGHabcdefgh";
	string eingabepr�fung2 = "12345678";
	string startpunkt, startpunkt_s, startpunkt_z;
	string zielpunkt, zielpunkt_s, zielpunkt_z;

public:
	Spiel();

	void anzeigen();
	void speichern();
	void laden();
	void ziehen();
	string input();


};
