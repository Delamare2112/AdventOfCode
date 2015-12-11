#include "Instruction.h"

Instruction::Instruction(std::ifstream& stream)
{
	std::size_t xpos;
	std::string line;
	stream >> line;
	action = Action::NOP;

	if(line[1] == 'o')
		action = Action::Toggle;
	else
		stream >> line;

	if(line[1] == 'n')
		action = Action::On;
	else if(line[1] == 'f')
		action = Action::Off;
	else if(action != Action::Toggle)
	{
		action = Action::NOP;
		return;
	}

	stream >> line;
	start.first = std::stoi(line, &xpos);
	line = line.substr(xpos + 1);
	start.second = std::stoi(line, &xpos);
	stream >> line;
	stream >> line;
	end.first = std::stoi(line, &xpos);
	line = line.substr(xpos + 1);
	end.second = std::stoi(line, &xpos);
}
