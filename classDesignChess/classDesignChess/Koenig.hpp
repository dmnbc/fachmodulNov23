#pragma once
#include "Figur.hpp"
class Koenig : 	public Figur
{
public:
	Koenig(std::string, bool);
	virtual	std::vector<std::string> erlaubteFelderErrechnen(std::string);
};
