#include "Feld.h"

Feld::Feld()
{
	feldNr = laufendeNr++;
	zeile  = feldNr / 8;
	spalte = feldNr % 8;
	feldFarbe = (zeile + spalte) % 2 ? 176 : 32;
	//std::cout << __LINE__ << ":" <<"Feld.cpp -> ctor Feld() "
	//	      << feldNr <<" in "<< zeile <<"," <<spalte 
	//	      << "\t" << feldFarbe <<		"\n";
// wie kann ich die Bezeichnung und die Farbe ermitteln ?
// es fehlenn mir zeilenNummer und SpaltenNummer um ( z+s)%2 zu rechnen
// aus der laufenden Nummer des Feldes ( 0 bis 63 ) kann man das berechnen
}

Feld::Feld(std::string koordinaten ) // a1 dunkel a2 hell a3 dunkel   
                    //   [0][1]         b1 hell  c1 dunkel 
	                //    a  3
{
	feldNr = laufendeNr++;
	zeile =  koordinaten[1] -'0';
	spalte = koordinaten[0] -'b';
	feldFarbe = (zeile + spalte) % 2 ? 176 : 32;
	// std::cout << __LINE__ << " feld.cpp " << koordinaten << "\n";
}
