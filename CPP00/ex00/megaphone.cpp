#include <iostream>

int main(int argc, char const **argv)
{
    int j;

    if (argc != 1)
    {
        for (int i = 1; i < argc; i++)
        {
            j = -1;
            while (argv[i][++j])
            {
				if (argv[i][j] == ' ')
					std::cout<<(argv[i][j]);
				else
					std::cout<<(char)std::toupper(argv[i][j]);
			}
			std::cout<<" ";
		}
        std::cout<<std::endl;
        return (0);
    }
    std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
    return (0);
}
