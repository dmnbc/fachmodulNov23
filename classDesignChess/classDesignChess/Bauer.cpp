#include "Bauer.hpp"
#include "Spiel.hpp"

Bauer::Bauer(std::string t, bool h)
{
	this->set_figurTyp(t);
	this->set_figurFarbe(h);
}

 std::vector<std::string> Bauer::erlaubteFelderErrechnen(std::string f)
{
	std::vector<std::string> eF{ ":"+f +": "};
	std::string nextVorne{ f.at(0),(char)(f.at(1) + (this->get_figurFarbe() ? -1 : 1)) };
	// Feld vor dem bauer in Zugrichtung  muss Leer sein
	if (Spiel::spielStand[nextVorne].figur->get_figurTyp() == "Leer")
	{
		eF.push_back(nextVorne);
		// in zeile 2 oder 7  zwei Felder vor ( aus Grundstellung ) 
		if (f.at(1) == '2' || f.at(1) == '7')
		{
			nextVorne = { f.at(0),(char)(f.at(1) + (this->get_figurFarbe() ? -2 : 2)) };
			if (Spiel::spielStand[nextVorne].figur->get_figurTyp() == "Leer")
			{
				eF.push_back(nextVorne);
			}
			else
			{
				eF.push_back("2. Schritt nach vorne geblockt");
			}
		}
	 }
	else
	{
		eF.push_back("nach vorne geblockt");
	}

	// könnte er schlagen, dann sind das auch erlaubte Felder
	std::string vorLinks{  char(f.at(0)-1),(char)(f.at(1) + (this->get_figurFarbe() ? -1 : 1)) };
	std::string vorRechts{ char(f.at(0)+1),(char)(f.at(1) + (this->get_figurFarbe() ? -1 : 1)) };

	if (aufDemSpielfeld(vorLinks) &&
		Spiel::spielStand[vorLinks].figur->get_figurTyp() != "Leer"
		&& !eigeneFigur(f,vorLinks))
	{
		eF.push_back("Kann schlagen ->"); 
		eF.push_back(vorLinks);
	}
	if (aufDemSpielfeld(vorRechts) &&
		Spiel::spielStand[vorRechts].figur->get_figurTyp() != "Leer"
		&& !eigeneFigur(f, vorRechts))
	{
		eF.push_back("Kann schlagen ->");
		eF.push_back(vorRechts);
	}


	return eF;
}