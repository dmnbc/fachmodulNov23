#include "Feld.h"

Feld::Feld()
{
	feldNr = laufendeNr++;
	zeile  = feldNr / 8;
	spalte = feldNr % 8;
	feldFarbe = (zeile + spalte) % 2 ? 176 : 32;
	
	figur = Figur('x');
}

Feld::Feld(std::string koordinaten ) // a1 dunkel a2 hell a3 dunkel   
                    //   [0][1]         b1 hell  c1 dunkel 
	                //    a  3
{
	feldNr = laufendeNr++;
	zeile =  koordinaten[1] -'0';
	spalte = koordinaten[0] -'b'; // 97 - 98    +2 
	feldFarbe = (zeile + spalte) % 2 ? 176 : 32;
	std::string offz{ " tpldklpt " };

	switch (zeile) 
	{
	case 2: 
	case 7: // Bauern aufstellen
		figur = Figur('B'+(zeile%2)*32);
		break;
	case 1:
	case 8: // Offz aufstellen
		try {
			figur = Figur(offz[spalte+2] - (zeile % 2) * 32);
		}
		catch (...)
		{
			std::cout << "fehler bei spalte " << spalte << "\n";
		}
		break;
	default: 
		figur = Figur(feldFarbe);

	}


	// std::cout << __LINE__ << " feld.cpp " << koordinaten << "\n";
}
