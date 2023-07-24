#include "HumanA.hpp"

HumanA::HumanA(std::string hName, Weapon &weapon): _name(hName), _weapon(weapon){
}

HumanA::~HumanA(void){}

void HumanA::attack(void){
	std::cout<<this->_name<<" attacks with their ";
	std::cout<<*this->_weapon.getType()<<std::endl;
}
