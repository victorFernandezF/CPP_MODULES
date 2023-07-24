#include "HumanB.hpp"

HumanB::HumanB(void){
	
}

HumanB::~HumanB(void){}

void HumanB::attack(void){
	std::cout<<this->_name<<" attacks with their ";
	std::cout<<this->_weapon->getType()<<std::endl;
}