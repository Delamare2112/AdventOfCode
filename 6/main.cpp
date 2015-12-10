#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Instruction.h"

using std::string;

int main(int argc, char const *argv[])
{
	if(argc == 1)
	{
		std::cout << "I need an input file.\n";
		return 1;
	}
	std::ifstream fileStream(argv[1]);

	uint grid[1000][1000] = {0};
	uint lit = 0;

	while(fileStream.good())
	{
		Instruction instruction(fileStream);
		for(int x = instruction.start.first; x <= instruction.end.first; x++)
		{
			for(int y = instruction.start.second; y <= instruction.end.second; y++)
			{
				uint& val = grid[x][y];
				switch(instruction.action)
				{
				case Action::Toggle:
					val += 2; break;
				case Action::On:
					val++; break;
				case Action::Off:
					val -= val ? 1 : 0; break;
				}
			}
		}
	}

	for(int x=0; x < 1000; x++) for(int y=0; y < 1000; y++) if(grid[x][y]) lit += grid[x][y];

	std::cout << "Lit: " << lit << std::endl;

	return 0;
}
