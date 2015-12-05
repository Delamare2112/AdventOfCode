#include <iostream>
#include <fstream>

#include "Box.h"

int main(int argc, char const *argv[])
{
	std::ifstream fileSteam("input.txt");
	std::string line;
	unsigned int totalSquareFeet = 0;
	while(fileSteam.good())
	{
		line = "";
		fileSteam >> line;
		totalSquareFeet += Box(line).GetSurfaceArea();
	}
	std::cout << "Total: " << totalSquareFeet << std::endl;
	return 0;
}
