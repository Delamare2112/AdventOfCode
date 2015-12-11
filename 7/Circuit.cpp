#include "Circuit.h"

std::unordered_map<std::string, uint16_t> Circuit::wires();

void Circuit::ExecuteLine(std::ifstream& stream)
{
  std::string word;
  word << stream;
  uint16_t* rhs
  if(word[0] > 96)
    rhs = &wires[word];
  else
  {
    if(word[0] == '');
  }
}
