#include "Feld.hpp"
#include "Turm.hpp"
#include "Springer.hpp"
#include "Bauer.hpp"
#include "Dame.hpp"
#include "Koenig.hpp"
#include "Leer.hpp"
#include "Laeufer.hpp"

#include <iostream>

Feld::Feld()
{
}

Feld::Feld(char s, char z): spalte{s}, zeile{z} // ctor, der die Grundstellung berechnet
{
	// std::cout << "Feld " << s << z << " wird erstellt\n";
	laufendeFeldnummer = (s - 65) * 8 + z - 48; // Umrechnung der Koordinate in laufende Feldnummer 1 bis 64
	hell = (s + z) % 2;      // dunkle, helle Felder
	switch (zeile)
	{
	case '1':
	case '8':
		{
			switch (spalte)  // für alle Figuren ctor(Kennung, Farbe)
			{
			case 'A':
			case 'H':
				figur = new Turm("T", zeile % 2 == 0);
				// Türme haben in der Grundstellung keine erlaubten Ziele
				break;
			case 'B':
			case 'G':
				figur = new Springer("S", zeile % 2 == 0);
				erlaubteZiele.push_back({ (char)(spalte - 1),(char)(zeile + (zeile % 2 ? 2 : -2)) });
				erlaubteZiele.push_back({ (char)(spalte + 1),(char)(zeile + (zeile % 2 ? 2 : -2)) });
				break;
			case 'C':
			case 'F':
				figur = new Laeufer("L", zeile % 2 == 0);
				// Läufer haben in der Grundstellung keine erlaubten Ziele
				break;
			case 'D':
				figur = new Dame("D", zeile % 2 == 0);
				// Damen haben in der Grundstellung keine erlaubten Ziele
				break;
			case 'E':
				figur = new Koenig("K", zeile % 2 == 0);
				// Könige haben in der Grundstellung keine erlaubten Ziele
				break;
			}
		}
		break;
	case '2':
	case '7':
	{
		figur = new Bauer("B", zeile % 2 == 1);
		erlaubteZiele.push_back({ spalte,(char)(zeile + (zeile % 2 ? -1 : 1)) });
		erlaubteZiele.push_back({ spalte,(char)(zeile + (zeile % 2 ? -2 : 2)) });
	}
	break;
	default:
			figur = new Leer("Leer", zeile % 2 == 1);
	}
}
