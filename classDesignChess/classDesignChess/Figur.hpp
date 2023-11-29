#pragma once


#include <string>
#include <vector>
class Figur
{
	std::string figurTyp;
	bool figurFarbe;

public:
	
	Figur();
	Figur(std::string, bool);

	 std::string get_figurTyp() {return figurTyp;}
	 bool get_figurFarbe() { return figurFarbe; }

	 void set_figurTyp(std::string t);
	 void set_figurFarbe(bool f);
	

	virtual std::vector<std::string> erlaubteFelderErrechnen(std::string);
	bool aufDemSpielfeld(std::string); 
	bool eigeneFigur(std::string, std::string); 
	bool nichtLeer(std::string);
	bool istLeer(std::string f) {return !nichtLeer(f); }
	bool schlagbarerGegner(std::string f, std::string nZ) { return !eigeneFigur(f, nZ) && aufDemSpielfeld(nZ);}
	

};

