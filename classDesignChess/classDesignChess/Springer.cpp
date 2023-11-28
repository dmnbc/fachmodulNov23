#include "Springer.hpp"
#include "Spiel.hpp"

#include <string>
#include <array>

Springer::Springer(std::string t, bool h)
{
	this->set_figurTyp(t);
	this->set_figurFarbe(h);
	

}

std::vector<std::string> Springer::erlaubteFelderErrechnen(std::string f)
{
	std::vector<std::string> eF{ ":" + f +":" };
	// bis zu 8 Felder können erreicht werden
	std::array<std::array<int, 2>, 8> relativeZiele{
				{{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}} };
	for (auto paar : relativeZiele)
	{
		std::string nextZiel{ (char)(f.at(0) + (paar.at(0))) ,(char)(f.at(1) + (paar.at(1))) };
		if (aufDemSpielfeld(nextZiel) && !eigeneFigur(f, nextZiel))
		{
			eF.push_back(nextZiel);
		}
	}
	return eF;
}
