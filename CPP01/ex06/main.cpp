#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		if (argc < 2)
			std::cout<<R<< "Error: Too few arguments."<<std::endl
			<<W<<" ex:. ./HarlFilter warning"<<std::endl;
		if (argc > 2)
			std::cout<<R<< "Error: Too many arguments."<<std::endl
			<<W<<" ex:. ./HarlFilter warning"<<W<<std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}
