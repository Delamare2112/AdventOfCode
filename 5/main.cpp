#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

	uint goodStrings = 0;

	while(fileSteam.good())
	{
		line = "";
		fileSteam >> line;

		bool pairRepeat = false;
		bool pairWithGap = false;
		char previousChar = 0;
		std::vector<string> pairs(line.length());

		for(int i=0; i < line.length(); i++)
		{
			char& c = line[i];
			if(!pairRepeat)
			{
				string thisPair;
				thisPair = previousChar;
				thisPair += c;
				const bool pairFound = std::find(pairs.begin(), pairs.end(), thisPair) != pairs.end();
				const bool row3 = i > 1 && c == line[i-1] && c == line[i-2];
				const bool row4 = i > 2 && c == line[i-3];
				if((pairFound && !row3) || (pairFound && row4))
					pairRepeat = true;
				else
					pairs.push_back(thisPair);
			}

			if(!pairWithGap && i > 1 && c == line[i-2])
				pairWithGap = true;
			previousChar = c;
		}
		if(pairWithGap && pairRepeat)
			goodStrings++;
	}

	std::cout << "Good Strings: " << goodStrings << std::endl;

	return 0;
}
