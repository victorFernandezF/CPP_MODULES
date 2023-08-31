/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:58:46 by victofer          #+#    #+#             */
/*   Updated: 2023/08/31 10:16:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(10), _energyPoints(2), _attackDamage(0){
	std::cout<<C<<"ClapTrap Default constructor."<<W<<std::endl;
}	
ClapTrap::ClapTrap(std::string name):_hitPoints(10), _energyPoints(2), _attackDamage(0){
	std::cout<<C<<"ClapTrap Constructor with name."<<W<<std::endl;
	this->_name = name;
}

ClapTrap::ClapTrap(ClapTrap &copy){
	std::cout<<C<<"ClapTrap Copy constructor."<<W<<std::endl;
	this->_name = copy.getName();
	this->_attackDamage = copy.getAttack();
	this->_energyPoints = copy.getEnergy();
	this->_hitPoints = copy.getHit();
}	

ClapTrap &ClapTrap::operator=(const ClapTrap &copy){
	std::cout<<C<<"ClapTrap Assignment operand."<<W<<std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout<<C<<"ClapTrap Destructor."<<W<<std::endl;
}

// G E T T E R  &&  S E T T T E R S 
std::string ClapTrap::getName(void) const{
	return (this->_name);
}
unsigned int ClapTrap::getHit(void) const{
	return (this->_hitPoints);
} 			
unsigned int ClapTrap::getEnergy(void) const{
	return (this->_energyPoints);
} 			
unsigned int ClapTrap::getAttack(void) const{
	return (this->_attackDamage);
}

void ClapTrap::setName(std::string name){
	this->_name = name;
}
void ClapTrap::setHit(int hit){
	this->_hitPoints = hit;
} 			
void ClapTrap::setEnergy(int energy){
	this->_energyPoints = energy;
} 			
void ClapTrap::setAttack(int attack){
	this->_attackDamage = attack;
}

void ClapTrap::printMessage(std::string action, std::string target, int amount){
	if (action == "attack")
		std::cout<<"ClapTrap "<<this->getName()<<G<<" attacks "<<W
		<<target<<", causing "<<G<<this->getAttack()<<W<<" points of damage"
		<<std::endl<<R<<" *"<<W<<"This action costs "<<R<<"1"
		<<W<<" energy point."<<W<<std::endl;
	if (action == "take")
		std::cout<<"ClapTrap "<<this->getName()<<G<<" has been attacked "<<W
		<<"causing the lost of "<<G<<amount<<W<<" hit points"<<std::endl;
	if (action == "repair")
		std::cout<<"ClapTrap "<<this->getName()<<G<<" repaired itself, "<<W
		<<" getting back "<<G<<amount<<W<<" hit points."<<std::endl<<R<<" *"
		<<W<<"This action costs "<<R<<"1"<<W<<" energy point."<<W<<std::endl;
}

// M E M B E R   F U N C T I O N S 

void ClapTrap::attack(const std::string& target){
	if (this->checkHitAndEnergy("attack", 0) == false)
		return ;
	this->setEnergy(this->_energyPoints - 1);
	this->printMessage("attack", target, 0);
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->checkHitAndEnergy("take damage", 1) == false)
		return ;
	if (amount > this->getHit())
		this->setHit(0);
	else
		this->setHit(this->_hitPoints - amount);
	this->printMessage("take", "", amount);

}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->checkHitAndEnergy("be repaired", 0) == false)
		return ;
	this->setEnergy(this->_energyPoints - 1);
	this->setHit(this->_hitPoints + amount);
	this->printMessage("repair", "", amount);
}

bool ClapTrap::checkHitAndEnergy(std::string action, int flag){
	
	if (this->getHit() <= 0 && flag == 1)
	{
		std::cout<<this->getName()<<R<<" is dead."<<W
		"Why do you still attacking?"<<std::endl;
		return (false);
	}
	if (this->getHit() <= 0)
	{
		std::cout<<R<<"**[ALERT]: "<<W<<"Unable to "<<action
		<<" because "<<this->getName()<<R<<" is dead."<<W<<std::endl;
		return (false);
	}
	if (this->getEnergy() <= 0)
	{
		std::cout<<R<<"**[ALERT]: "<<W<<"Unable to "<<action
		<<" because "<<this->getName()<<R<<" has no energy points"<<W<<std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::printStatus(void){
	std::cout<<std::endl;
	std::cout<<Y<<" _______[STATUS]________" <<std::endl
	<<std::endl
	<<"  NAME: "<<this->getName()<<std::endl
	<<"  HIT: "<<this->getHit()<<std::endl
	<<"  ENERGY:"<<this->getEnergy()<<std::endl
	<<"  ATTACK: "<<this->getAttack()<<std::endl
	<<Y<<" _______________________"<<std::endl;
	std::cout<<W<<std::endl;
}
