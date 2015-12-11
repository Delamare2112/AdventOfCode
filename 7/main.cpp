#include <iostream>
#include <fstream>

using std::string;

int main(int argc, char const *argv[])
{
	if(argc == 1)
	{
		std::cout << "I need an input file.\n";
		return 1;
	}
	std::ifstream fileSteam(argv[1]);
	string line;

	while(fileSteam.good())
	{
		line = "";
		fileSteam >> line;

	}


	return 0;
}
