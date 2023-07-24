#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon *weapon){
	this->_name = name;
}

HumanA::~HumanA(void){}

void HumanA::attack(void){
	std::cout<<this->_name<<" attacks with their ";
	std::cout<<this->_weapon->getType()<<std::endl;
}