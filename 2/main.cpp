#include <iostream>
#include <fstream>

#include "Box.h"

int main(int argc, char const *argv[])
{
	std::ifstream fileSteam("input.txt");
	std::string line;
	uint totalSquareFeet = 0;
	uint totalFeetOfRibbon = 0;
	while(fileSteam.good())
	{
		line = "";
		fileSteam >> line;
		Box b(line);
		totalSquareFeet += b.GetSurfaceArea();
		totalFeetOfRibbon += b.GetRibbonAmmount();
	}
	std::cout << "SurfaceArea: " << totalSquareFeet << std::endl;
	std::cout << "RibbonAmmount: " << totalFeetOfRibbon << std::endl;
	return 0;
}
