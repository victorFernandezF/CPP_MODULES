#include "Zombie.hpp"
#include "colours.h"

Zombie* zombieHorde( int N, std::string name );

void leaks(void)
{
	std::cout<<M<<" \n-- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex01");
}

int main(void)
{
	atexit(leaks);
    Zombie *horde;
    int N;
    
	N = 10;
    std::cout<<BM<<" -- [ TEST 1 ] --" <<W<<std::endl;
    std::cout<<BB<<"  *We will create a Zomby horde "
	<<"of "<<N<<" zombies"<<G<<std::endl;
    horde = zombieHorde(N, "Mortadelo");
    for (int i = 0; i < N; i++)
        horde[i].announce();
    std::cout<<BB<<"\n  *We will now delete the Zomby horde."<<W<<std::endl;
    delete [] horde;
    return (0);
}
