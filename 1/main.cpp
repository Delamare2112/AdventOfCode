#include <iostream>
#include <fstream>
#include <string>

int main()
{
	int santaPosition = 0;
	int basementCharacter = 0;
	std::string line;
	std::ifstream fileSteam("input.txt");
	if(fileSteam.good())
	{
		line = "";
		fileSteam >> line;
		for(int i = 0; i < line.length(); i++)
		{
			santaPosition += line[i] == '(' ? 1 : -1;
			if(santaPosition < 0 && !basementCharacter)
			{
				basementCharacter = i + 1;
			}
		}
	}
	std::cout << "Santa is on floor: " << santaPosition << std::endl;
	std::cout << "Santa entered the basement at char: ";
	if(basementCharacter)
		std::cout << basementCharacter;
	else
		std::cout << "never";
	std::cout << std::endl;
}