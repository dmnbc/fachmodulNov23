#pragma once

#include <array>
#include <map>    // aus STL 
#include <string>
#include <iostream>
#include <fstream>

#include "Feld.h"

using namespace std; 

class Spiel
{
private:
	ofstream ofile;
	map<string, Feld> spielmap;

public:
	Spiel();

	void anzeigen(bool);


};

