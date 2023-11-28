#include "Figur.h"
#include <iostream>
#include "Feld.h"
#include "Turm.h"
#include "Bauer.h"
#include "Pferd.h"
#include "Laeufer.h"
#include "Dame.h"
#include "Leer.h"
#include "Koenig.h"

Figur::Figur()
{
	//std::cout << __LINE__ << ":" << __FILE__ << "ctor Figur() \n";	
}

Figur::Figur(char rang)
{
	darstellung = rang;
}
