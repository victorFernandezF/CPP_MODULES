#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	this->setType(type);
}
Weapon::~Weapon(void){}

std::string* Weapon::getType(void){
	std::string &ref = this->_type;
	return (&ref);
}

void Weapon::setType(std::string type){
	this->_type = type;
}