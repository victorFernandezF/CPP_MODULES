#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file("file.txt");
	std::string con;
	while (file >> con)
		std::cout<<con<<std::endl;
	return 0;
}