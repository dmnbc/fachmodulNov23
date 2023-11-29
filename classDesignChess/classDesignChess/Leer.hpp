#pragma once
#include <string>
#include "Figur.hpp"
class Leer : public Figur
{
public:
	Leer(std::string, bool);
	virtual	std::vector<std::string> erlaubteFelderErrechnen(std::string);
};

