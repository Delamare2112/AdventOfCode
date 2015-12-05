#include "Box.h"

Box::Box(std::string line)
{
	std::size_t xpos;
	l = std::stoi(line, &xpos);
	line = line.substr(xpos + 1);
	w = std::stoi(line, &xpos);
	h = std::stoi(line.substr(xpos + 1), nullptr);
}

uint Box::GetSurfaceArea()
{
	uint areaLW = l*w;
	uint areaWH = w*h;
	uint areaLH = l*h;
	uint slack = areaLW < areaWH ? areaLW : areaWH;
	if(slack > areaLH)
		slack = areaLH;
	return 2*areaLW + 2*areaWH + 2*areaLH + slack;
}

uint Box::GetRibbonAmmount()
{
	uint perimLW = l+l+w+w;
	uint perimWH = w+w+h+h;
	uint perimLH = l+l+h+h;
	uint ribbon = perimLW < perimWH ? perimLW : perimWH;
	if(ribbon > perimLH)
		ribbon = perimLH;
	return ribbon + (l*w*h);
}