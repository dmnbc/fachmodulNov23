#include "Feld.h"
#include <string>
#include "Leer.h"
#include "Bauer.h"
#include "Turm.h"
#include "Koenig.h"
#include "Dame.h"
#include "Pferd.h"
#include "Laeufer.h"
#include <iostream>

Feld::Feld()
{
	feldNr = laufendeNr++;
	zeile = feldNr / 8;
	spalte = feldNr % 8;
	feldFarbe = (zeile + spalte) % 2 ? 176 : 32;
	//std::cout << __LINE__ << ":" <<"Feld.cpp -> ctor Feld() "
	//	      << feldNr <<" in "<< zeile <<"," <<spalte 
	//	      << "\t" << feldFarbe <<		"\n";
// wie kann ich die Bezeichnung und die Farbe ermitteln ?
// es fehlenn mir zeilenNummer und SpaltenNummer um ( z+s)%2 zu rechnen
// aus der laufenden Nummer des Feldes ( 0 bis 63 ) kann man das berechnen
}

Feld::Feld(std::string koordinaten) // a1 dunkel a2 hell a3 dunkel   
//   [0][1]         b1 hell  c1 dunkel 
//    a  3
{
	feldNr = laufendeNr++;
	zeile = koordinaten[1] - '0';
	spalte = koordinaten[0] - 'b';
	// feldFarbe = (zeile + spalte) % 2 ? 176 : 32;
	// std::cout << __LINE__ << " feld.cpp " << koordinaten << "\n";
	// weiß groß - schwarz klein
	

	switch (zeile)
	{
	case 2:
	case 7:
		Bauer('B' + (zeile % 2) * 32);
		break;
	case 1:
	case 8:
			switch (Off[spalte + 2] - (zeile % 2) * 32)
			{
			case 't':
			case 'T':
				Turm(Off[spalte + 2] - (zeile % 2) * 32);
				break;
			case 'l':
			case 'L':
				Laeufer(Off[spalte + 2] - (zeile % 2) * 32);
				break;
			case 'p':
			case 'P':
				Pferd(Off[spalte + 2] - (zeile % 2) * 32);
				break;
			case 'd':
			case 'D':
				Dame(Off[spalte + 2] - (zeile % 2) * 32);
				break;
			case 'k':
			case 'K':
				Koenig(Off[spalte + 2] - (zeile % 2) * 32);
				break;

			}
		break;
	default:
		Leer();
	}
}
