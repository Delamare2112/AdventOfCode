#include <iostream>
#include <fstream>
#include <string>

int main()
{
	int number = 0;
	std::string line;
	std::ifstream fileSteam("input.txt");
	while(fileSteam.good())
	{
		line = "";
		fileSteam >> line;
		for(char& c : line)
			number += c == '(' ? 1 : -1;
	}
	std::cout << number << std::endl;
}