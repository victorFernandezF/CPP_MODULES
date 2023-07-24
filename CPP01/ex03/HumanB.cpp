#include "HumanB.hpp"

HumanB::HumanB(std::string humanName): _weapon(NULL){
	this->_name = humanName;
}

HumanB::~HumanB(void){}

void HumanB::attack(void){
	if (this->_weapon->getType() == NULL)
		std::cout<<this->_name<<" has no weapon"<<std::endl;
	else {
		std::cout<<this->_name<<" attacks with their ";
		std::cout<<*this->_weapon->getType()<<std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}