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

	const string vowelchars = "aeiou";
	const string badStrings[4] = {"ab", "cd", "pq", "xy"};
	uint goodStrings = 0;

	while(fileSteam.good())
	{
		line = "";
		fileSteam >> line;
		bool bad = false;
		bool doubleLetters = false;
		char previousChar = 0;
		uint vowels = 0;
		for(int i=0; i < 4; i++)
		{
			if(line.find(badStrings[i]) != string::npos)
			{
				bad	= true;
				break;
			}
		}
		if(bad)
			continue;
		for(int i=0; i < line.length(); i++)
		{
			char& c = line[i];
			if(vowels <= 3 && vowelchars.find(c) != std::string::npos)
			{
				vowels++;
			}
			if(c == previousChar)
				doubleLetters = true;
			previousChar = c;
		}
		if(doubleLetters && vowels > 2)
			goodStrings++;
	}

	std::cout << "Good Strings: " << goodStrings << std::endl;

	return 0;
}
