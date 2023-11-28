#include "Laeufer.hpp"

Laeufer::Laeufer(std::string t, bool h)
{
	this->set_figurTyp(t);
	this->set_figurFarbe(h);
}

std::vector<std::string> Laeufer::erlaubteFelderErrechnen(std::string f)
{
	std::vector<std::string> eF{ ":" + f + ":" };
	// diagonal in 4 Richtungen
	// solange noch auf Spielfeld && Feld leer
	std::string nextZiel{ (char)(f.at(0) + 1) ,(char)(f.at(1) + 1) };
	while (aufDemSpielfeld(nextZiel) && istLeer(nextZiel))
	{
		eF.push_back(nextZiel); 
		nextZiel = { (char)(nextZiel.at(0) + 1) ,(char)(nextZiel.at(1) + 1) }; 
	}

	// kann auf dem nächsten Feld ein Gegner geschlagen werden ?
	if (schlagbarerGegner(f,nextZiel)) {
		eF.push_back("Kann schlagen ->");
		eF.push_back(nextZiel);
	   }


	nextZiel = { (char)(f.at(0) -1) ,(char)(f.at(1) + 1) };
	while (aufDemSpielfeld(nextZiel) && istLeer(nextZiel))
	{
		eF.push_back(nextZiel);
		nextZiel = { (char)(nextZiel.at(0) - 1) ,(char)(nextZiel.at(1) + 1) };
	}
	// kann auf dem nächsten Feld ein Gegner geschlagen werden ?
	if (schlagbarerGegner(f, nextZiel)) {
		eF.push_back("Kann schlagen ->");
		eF.push_back(nextZiel);
	}

	nextZiel = { (char)(f.at(0) - 1) ,(char)(f.at(1) - 1) };
	while (aufDemSpielfeld(nextZiel) && istLeer(nextZiel))
	{
		eF.push_back(nextZiel);
		nextZiel = { (char)(nextZiel.at(0) + 1) ,(char)(nextZiel.at(1) - 1) };
	}
	// kann auf dem nächsten Feld ein Gegner geschlagen werden ?
	if (schlagbarerGegner(f, nextZiel)) {
		eF.push_back("Kann schlagen ->");
		eF.push_back(nextZiel);
	}
	 nextZiel = { (char)(f.at(0) - 1) ,(char)(f.at(1) + 1) };
	while (aufDemSpielfeld(nextZiel) && istLeer(nextZiel))
	{
		eF.push_back(nextZiel);
		nextZiel = { (char)(nextZiel.at(0) - 1) ,(char)(nextZiel.at(1) - 1) };
	}
	// kann auf dem nächsten Feld ein Gegner geschlagen werden ?
	if (schlagbarerGegner(f, nextZiel)) {
		eF.push_back("Kann schlagen ->");
		eF.push_back(nextZiel);
	}


	return eF;
}
