#include <iostream>
#include <string>
#include "md5.h"

int main(int argc, char const *argv[])
{
	if(argc == 1)
	{
		std::cout << "I need a secret key.\n";
		return 1;
	}

	const std::string key = argv[1];
	std::string result = "1234567890";
	uint number = 0;
	while(result.substr(0, 6) != "000000")
	{
		result = md5(key + std::to_string(number++));
	}

	std::cout << "Number: " << number - 1 << std::endl;

	return 0;
}
