#include <iostream>
#include <fstream>
#include <unordered_map>

int main(int argc, char const *argv[])
{
	std::ifstream fileSteam("input.txt");
	std::string line;

	std::unordered_map<int, std::unordered_map<int, bool>> visited;
	int x=0, y=0, houses=1;
	visited[x][y] = true;

	while(fileSteam.good())
	{
		line = "";
		fileSteam >> line;
		for(char& c : line)
		{
			switch(c)
			{
				case '^':
					y++; break;
				case 'v':
					y--; break;
				case '>':
					x++; break;
				case '<':
					x--; break;
			}
			bool& oldHouse = visited[x][y];
			if(!oldHouse)
			{
				houses++;
				oldHouse = true;
			}
		}
	}
	std::cout << "Houses: " << houses << std::endl;
	return 0;
}
