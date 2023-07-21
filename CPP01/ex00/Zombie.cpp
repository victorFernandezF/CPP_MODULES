#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    std::cout<<name<<" Created"<<std::endl;
    this->_name = name;
}

Zombie::~Zombie(void){
    std::cout<<this->_name<<" has been destroyed"<<std::endl;
}

void Zombie::announce(void){
    std::cout<<this->_name<<":  BraiiiiiiinnnzzzZ..."<<std::endl;
}
