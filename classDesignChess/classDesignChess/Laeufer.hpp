#pragma once
#include "Figur.hpp"
class Laeufer : public Figur
{
public:
	Laeufer(std::string, bool);
	virtual	std::vector<std::string> erlaubteFelderErrechnen(std::string);
};

