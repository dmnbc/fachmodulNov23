#include "Dame.hpp"
#include "Laeufer.hpp"
#include "Turm.hpp"
#include <vector>
#include <string>
#include <iostream>
Dame::Dame(std::string t, bool h)
{
	this->set_figurTyp(t);
	this->set_figurFarbe(h);
}

std::vector<std::string> Dame::erlaubteFelderErrechnen(std::string f)
{
	std::vector<std::string> eF{ ":" + f + ":" };
	/*Laeufer* tempL = dynamic_cast<Laeufer*>(this) ;
	std::vector<std::string> eFL = tempL->erlaubteFelderErrechnen(f);*/

	Laeufer* tempL = new Laeufer("L", this->get_figurFarbe());
	std::vector<std::string> eFL = tempL->erlaubteFelderErrechnen(f);
	eF.insert(eF.end(),	eFL.begin(),  eFL.end() );

	Turm* tempT = new Turm("T", this->get_figurFarbe());
	                         eFL = tempT->erlaubteFelderErrechnen(f);
	eF.insert(eF.end(), eFL.begin(), eFL.end());
	
	return eF; 
	
	
	
	//return std::vector<std::string>();
}
