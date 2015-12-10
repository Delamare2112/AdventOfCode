#include "Instruction.h"

Instruction::Instruction(std::ifstream& stream)
{
  std::size_t xpos;
  std::string line;
  stream >> line;
//  std::cout << "Action: " << line << std::endl;
  if(line[1] == 'o')
  {
    action = Action::Toggle;
    std::cout << "Toggle ";
  }
  else
    stream >> line;
  if(line[1] == 'n')
  {
    action = Action::On;
    // stream >> line;
    std::cout << "On ";
  }
  else if(line[1] == 'f')
  {
    action = Action::Off;
    // stream >> line;
    std::cout << "Off ";
  }
  else
  {
    std::cout << "line bad: " << line;
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
  std::cout << start.first << " " << start.second << " " << end.first << " " << end.second << std::endl;
// turn on 0,0 through 999,999
//	l = std::stoi(line, &xpos);
//	line = line.substr(xpos + 1);
//	w = std::stoi(line, &xpos);
//	h = std::stoi(line.substr(xpos + 1), nullptr);
}
