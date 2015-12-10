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

	bool grid[1000][1000] = {0};
  uint lit = 0;

	while(fileStream.good())
	{
    // std::cout << line << std::endl;
    Instruction instruction(fileStream);
    for(int x=0; x < 1000; x++)
      for(int y=0; y < 1000; y++)
        if(grid[x][y])
          ; // std::cout << "Something is true." << std::endl;
    for(int x=instruction.start.first; x<=instruction.end.first;x++)
      for(int y=instruction.start.second; y<=instruction.end.second;y++)
      {
        bool& val = grid[x][y];
        // std::cout << val << " to ";
        switch(instruction.action)
        {
        case Action::Toggle:
          val = !val; break;
        case Action::On:
          val = true; break;
        case Action::Off:
          val = false; break;
        }
        lit += val;
        // std::cout << val << std::endl;
      }
	}

  std::cout << "Lit: " << lit << std::endl;

	return 0;
}
