#include <string>

class Box
{
private:
	int l,w,h;
public:
	Box(std::string line);
	int GetSurfaceArea();
};