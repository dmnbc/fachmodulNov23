#include "Koenig.hpp"

Koenig::Koenig(std::string t, bool h)
{
	this->set_figurTyp(t);
	this->set_figurFarbe(h);
}

std::vector<std::string> Koenig::erlaubteFelderErrechnen(std::string)
{
	return std::vector<std::string>();
}
