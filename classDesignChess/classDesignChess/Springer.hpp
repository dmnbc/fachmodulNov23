#pragma once
#include "Figur.hpp"
class Springer : 	public Figur
{
public:
	Springer(std::string, bool);
	virtual	std::vector<std::string> erlaubteFelderErrechnen(std::string);

};

