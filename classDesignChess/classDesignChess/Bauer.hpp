#pragma once

#include "Figur.hpp"
class Bauer :	public Figur
{
public:
	Bauer(std::string, bool);
	virtual	std::vector<std::string> erlaubteFelderErrechnen(std::string );
};

