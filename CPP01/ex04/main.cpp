#include <iostream>
#include <fstream>


static int isSpaceTabNewLine(char c){
	return (c == ' ' || c == '\t' || c == '\n');
}

static void replace(char **argv, std::string fName, std::ifstream &file){
	char c;
	std::ofstream ofile;
	std::string word;

	ofile.open(fName, std::ofstream::out | std::ofstream::trunc);
	while (file >>std::noskipws>>c)
	{
		if (!isSpaceTabNewLine(c))
			word += c;
		if (isSpaceTabNewLine(c))
		{
			if (word == argv[2])
				ofile<<argv[3];
			else
				ofile<<word;
			ofile<<c;
			word = "";
		}
	}
	ofile.close();
}

int main(int argc, char **argv)
{
	std::ifstream file;
	std::string rest;
	
	if (argc != 4)
	{
		std::cout<<"ERROR: Too few arguments."<<std::endl
		<<" [filename][s1][s2]"<<std::endl;
		return 1;
	}
	rest = ".replace";
	std::string newFileName(argv[1]);
	newFileName += rest;
	file.open(argv[1]);
	if (file.fail())
	{
		std::cout<<"Input file does not exist or is corrupted"<<std::endl;
		return 1;
	}
	replace(argv, newFileName, file);
	std::cout<<"SUCCESS"<<std::endl;
	file.close();
	return 0;
}