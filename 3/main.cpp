#include <iostream>
#include <fstream>
#include <unordered_map>

struct Position
{
	int x=0, y=0;
};

int main(int argc, char const *argv[])
{
	std::ifstream fileSteam("input.txt");
	std::string line;

	std::unordered_map<int, std::unordered_map<int, bool>> visited;
	int houses=1;
	visited[0][0] = true;

	bool isSanta = true;
	Position robo, santa;

	while(fileSteam.good())
	{
		line = "";
		fileSteam >> line;
		for(char& c : line)
		{
			Position& pos = isSanta ? santa : robo;
			switch(c)
			{
				case '^':
					pos.y++; break;
				case 'v':
					pos.y--; break;
				case '>':
					pos.x++; break;
				case '<':
					pos.x--; break;
			}
			bool& oldHouse = visited[pos.x][pos.y];
			if(!oldHouse)
			{
				houses++;
				oldHouse = true;
			}
			isSanta = !isSanta;
		}
	}
	std::cout << "Houses: " << houses << std::endl;
	return 0;
}
