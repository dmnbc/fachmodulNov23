#include "Turm.hpp"

Turm::Turm(std::string t, bool h) 
{
	this->set_figurTyp(t);
	this->set_figurFarbe(h);
}

std::vector<std::string> Turm::erlaubteFelderErrechnen(std::string f)
{
	std::vector<std::string> eF{ ":" + f + ":" };
	// horizonzal/vertikal in 4 Richtungen
	// solange noch auf Spielfeld && Feld leer
	std::string nextZiel{ (char)(f.at(0)) ,(char)(f.at(1) + 1) }; // eine Zeile nach unten
	while (aufDemSpielfeld(nextZiel) && istLeer(nextZiel))
	{
		eF.push_back(nextZiel);
		nextZiel = { (char)(nextZiel.at(0)) ,(char)(nextZiel.at(1) + 1) };
	}

	// kann auf dem nächsten Feld ein Gegner geschlagen werden ?
	if (schlagbarerGegner(f, nextZiel)) {
		eF.push_back("Kann schlagen ->");
		eF.push_back(nextZiel);
	}


	nextZiel = { (char)(f.at(0)) ,(char)(f.at(1) - 1) };  // eine Zeil hoch
	while (aufDemSpielfeld(nextZiel) && istLeer(nextZiel))
	{
		eF.push_back(nextZiel);
		nextZiel = { (char)(nextZiel.at(0)) ,(char)(nextZiel.at(1) - 1) };
	}
	// kann auf dem nächsten Feld ein Gegner geschlagen werden ?
	if (schlagbarerGegner(f, nextZiel)) {
		eF.push_back("Kann schlagen ->");
		eF.push_back(nextZiel);
	}

	nextZiel = { (char)(f.at(0) - 1) ,(char)(f.at(1)) }; // eine Spalte nach links
	while (aufDemSpielfeld(nextZiel) && istLeer(nextZiel))
	{
		eF.push_back(nextZiel);
		nextZiel = { (char)(nextZiel.at(0) - 1) ,(char)(nextZiel.at(1)) };
	}
	// kann auf dem nächsten Feld ein Gegner geschlagen werden ?
	if (schlagbarerGegner(f, nextZiel)) {
		eF.push_back("Kann schlagen ->");
		eF.push_back(nextZiel);
	}
	nextZiel = { (char)(f.at(0) + 1) ,(char)(f.at(1)) }; // ein Spalte nach rechts
	while (aufDemSpielfeld(nextZiel) && istLeer(nextZiel))
	{
		eF.push_back(nextZiel);
		nextZiel = { (char)(nextZiel.at(0) + 1) ,(char)(nextZiel.at(1) ) };
	}
	// kann auf dem nächsten Feld ein Gegner geschlagen werden ?
	if (schlagbarerGegner(f, nextZiel)) {
		eF.push_back("Kann schlagen ->");
		eF.push_back(nextZiel);
	}

	return eF;
}
