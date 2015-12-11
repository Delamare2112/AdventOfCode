#pragma once

#include <fstream>
#include <unordered_map>
#include <string>

class Circuit
{
  static std::unordered_map<std::string, uint16_t> wires;
  static void ExecuteLine(std::ifstream& stream);
};

