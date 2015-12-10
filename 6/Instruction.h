#include <iostream>
#include <fstream>
#include <string>

enum Action
{
  On, Off, Toggle, NOP
};

class Instruction
{
public:
  std::pair<int, int> start, end;
  Action action;
  Instruction(std::ifstream& stream);
};
