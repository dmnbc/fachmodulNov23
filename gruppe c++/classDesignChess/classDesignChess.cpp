// // classDesignChess.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Spiel.h"
#include "Feld.h"
#include "Koenig.h"


int Feld::laufendeNr = 0;

int main()
{
    Spiel s1;
    s1.anzeigen();
    s1.anzeigen();
    s1.input();
}