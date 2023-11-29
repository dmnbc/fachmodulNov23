#pragma once

#include <iostream>
#include <string>
#include "Figur.h"

class Feld
{
private:
	char feldFarbe = 32;
	Figur figur;
	int feldNr = 0;
	int zeile = 0;
	int spalte = 0;
	std::string Off = " tplkdlpt ";



public:

	static int laufendeNr;
	Feld();
	Feld(std::string);

	char get_feldFarbe() { return feldFarbe; }
	int get_feldNr() { return feldNr; }
	int get_zeile() { return zeile; }
	int get_spalte() { return spalte; }

	Figur get_figur() { return figur; }
};


