#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	char c;
	std::ifstream file;
	std::ofstream ofile;
	std::string con;
	std::string str(argv[1]);
	std::string rest;
	
	if (argc != 4)
		return 1;
	rest = ".replace";
	str += rest;
	file.open(argv[1]);
	if (file.fail())
	{
		std::cout<<"Input file does not exist or is corrupted"<<std::endl;
		return 1;
	}
	ofile.open(str, std::ofstream::out | std::ofstream::trunc);
	while (file >> con >>c)
	{
		if (c == '\n')
			ofile<<"\n";
		if (c == ' ')
			ofile<< " ";
		std::cout<<con<<"/"; 
		if (con == argv[2])
			ofile<<argv[3];
		else
			ofile<<con;
	}
	return 0;
}