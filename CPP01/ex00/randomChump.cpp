#include "Zombie.hpp"

void randomChump(std::string name){
    Zombie zom;
    zom.setName(name);
    zom.announce();
}
