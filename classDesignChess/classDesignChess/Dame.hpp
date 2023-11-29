#pragma once
#include <string>
#include "Figur.hpp"
class Dame : public Figur
{
public:
	Dame(std::string, bool);
	virtual	std::vector<std::string> erlaubteFelderErrechnen(std::string);
};

