#pragma once
#include "Figur.hpp"
class Turm : public Figur
{
public:
	Turm(std::string, bool);
	virtual	std::vector<std::string> erlaubteFelderErrechnen(std::string);
};

