#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    std::string stackName;
    std::string heapName;
    std::cout<<std::endl<<"\x1B[33mInsert a name for zombie created on stack> \x1B[0m";
    std::getline(std::cin, stackName);
    std::cout<<"\x1B[33mInsert a name for zombie created on heap> \x1B[0m";
    std::getline(std::cin, heapName);
    std::cout<<std::endl;
    Zombie *zombo = newZombie(heapName);
    zombo->announce();
    randomChump(stackName);
    delete zombo;
    return (0);
}
