#include "Zombie.hpp"
#include "colours.h"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

void leaks(void)
{
	std::cout<<M<<" \n-- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
}

int main(void)
{
	atexit(leaks);
    std::string stackName;
    std::string heapName;
    std::cout<<std::endl<<Y<<"Insert a name for zombie created on stack>"<<W;
    std::getline(std::cin, stackName);
    std::cout<<Y<<"Insert a name for zombie created on heap>"<<W;
    std::getline(std::cin, heapName);
    std::cout<<std::endl;
    Zombie *zombo = newZombie(heapName);
    zombo->announce();
    randomChump(stackName);
    delete zombo;
    return (0);
}
