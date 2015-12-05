#include "Box.h"

Box::Box(std::string line)
{
	std::size_t xpos;
	l = std::stoi(line, &xpos);
	line = line.substr(xpos + 1);
	w = std::stoi(line, &xpos);
	h = std::stoi(line.substr(xpos + 1), nullptr);
}

int Box::GetSurfaceArea()
{
	unsigned int areaLW = l*w;
	unsigned int areaWH = w*h;
	unsigned int areaLH = l*h;
	unsigned int slack = areaLW < areaWH ? areaLW : areaWH;
	if(slack > areaLH)
		slack = areaLH;
	return 2*areaLW + 2*areaWH + 2*areaLH + slack;
}