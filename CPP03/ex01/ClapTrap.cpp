/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:58:46 by victofer          #+#    #+#             */
/*   Updated: 2023/08/08 18:42:41 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(100), _energyPoints(50), _attackDamage(20){
	std::cout<<B<<"ClapTrap Default constructor."<<W<<std::endl;
}	
ClapTrap::ClapTrap(std::string name):_hitPoints(100), _energyPoints(50), _attackDamage(20){
	std::cout<<B<<"ClapTrap Constructor with name."<<W<<std::endl;
	this->_name = name;
}

ClapTrap::ClapTrap(ClapTrap &copy){
	std::cout<<B<<"ClapTrap Copy constructor."<<W<<std::endl;
	this->_name = copy.getName();
	this->_attackDamage = copy.getAttack();
	this->_energyPoints = copy.getEnergy();
	this->_hitPoints = copy.getHit();
}	

ClapTrap &ClapTrap::operator=(const ClapTrap &copy){
	std::cout<<B<<"ClapTrap Assignment operand."<<W<<std::endl;
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
	std::cout<<B<<"ClapTrap Destructor."<<W<<std::endl;
}

// G E T T E R  &&  S E T T T E R S 
std::string ClapTrap::getName(void){
	return (this->_name);
}
int ClapTrap::getHit(void){
	return (this->_hitPoints);
} 			
int ClapTrap::getEnergy(void){
	return (this->_energyPoints);
} 			
int ClapTrap::getAttack(void){
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

// M E M B E R   F U N C T I O N S 

// Attacks a target. This action costs one energy point.
void ClapTrap::attack(const std::string& target){
	if (this->checkHitAndEnergy() == false)
		return ;
	std::cout<<"ClapTrap "<<this->getName()<<" attacks "
	<<target<<", causing "<<this->getAttack()<<" points of damage"
	<<std::endl;
	this->setEnergy(this->_energyPoints - 1);
}

// Decrements the number of hit points by the given amount. 
void ClapTrap::takeDamage(unsigned int amount){
	if (this->checkHitAndEnergy() == false)
		return ;
	if (amount > this->getHit())
		this->setHit(0);
	else
		this->setHit(this->_hitPoints - amount);
	std::cout<<"ClapTrap "<<this->getName()<<" has been attacked "
	<<" causing the lost of "<<amount<<" hit points"
	<<std::endl;
}

// Repaires itself. This action costs one energy point.
// It will get back 1 hit point.
void ClapTrap::beRepaired(unsigned int amount){
	if (this->checkHitAndEnergy() == false)
		return ;
	std::cout<<"ClapTrap "<<this->getName()<<" repaired itself"
	<<", getting back "<<amount<<" hit points."
	<<std::endl;
	this->setEnergy(this->_energyPoints - 1);
	this->setHit(this->_hitPoints + amount);
}

// Checks if claptrap has enought energy and hit points to continue.
bool ClapTrap::checkHitAndEnergy(void){
	
	if (this->getHit() <= 0)
	{
		std::cout<<R<<"[ALERT]: NO HIT POINTS!"<<W<<std::endl;
		return (false);
	}
	if (this->getEnergy() <= 0)
	{
		std::cout<<R<<"[ASLERT]: NO ENERGY POINTS!"<<W<<std::endl;
		return (false);
	}
	return (true);
}

// Prints the status current of claptrap. 
void ClapTrap::printStatus(void){
	std::cout<<std::endl;
	std::cout<<Y<<" -- [STATUS] --" <<std::endl
	<<Y<<"|             	|"<<std::endl
	<<Y<<"|"<<W<<"  HIT: "<<this->getHit()<<Y<<"	|"<<std::endl
	<<Y<<"|"<<W<<"  ENERGY:"<<this->getEnergy()<<Y<<"	|"<<std::endl
	<<Y<<"|"<<W<<"  ATTACK: "<<this->getAttack()<<Y<<"	|"<<std::endl
	<<Y<<"|             	|"<<std::endl
	<<" --------------"<<std::endl;
	std::cout<<W<<std::endl;
}
