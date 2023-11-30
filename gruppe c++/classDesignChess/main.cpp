#include <iostream>
#include "Spiel.h"
#include "Feld.h"
#include "Koenig.h"


int Feld::laufendeNr = 0;
bool spielende = false;
bool endbedingung = false;

int main()
{
    Spiel s1;
    s1.anzeigen();
    //s1.input();
    while (spielende == false)
    {
        s1.input();
        s1.ziehen();
        
        //regelprüfung
        //wenn korrekt -> Spielhistorie
        //Figur wird bewegt
        //bei Schachmatt/Unentschieden endbedigung = true
        if (endbedingung)
        {
            spielende = true;
        }
        //clear screen
        //anzeige letzer zug
        //spielfeld neu anzeigen mit veränderten positionen der figuren
        s1.anzeigen(); //temp
        s1.speichern();
    }
}
