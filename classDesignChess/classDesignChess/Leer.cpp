#include "Leer.hpp"

Leer::Leer(std::string t, bool h)
{
	this->set_figurTyp(t);
	this->set_figurFarbe(h);
}

std::vector<std::string> Leer::erlaubteFelderErrechnen(std::string)
{
	return std::vector<std::string>();
}
