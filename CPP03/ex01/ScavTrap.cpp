/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:08:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/08 18:43:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout<<BB<<" ScavTrap Default constructor."<<W<<std::endl;
}	
ScavTrap::ScavTrap(std::string name){
	std::cout<<BB<<" ScavTrap Constructor with name."<<W<<std::endl;
	this->setName(name);
}

ScavTrap::~ScavTrap(){
	std::cout<<BB<<" ScavTrap Destructor."<<W<<std::endl;
}

void ScavTrap::guardGate(){
	std::cout<<"ScavTrap "<<this->getName()
	<<" is in Gate Keeper mode."<<std::endl;
}

ScavTrap::ScavTrap(ScavTrap &copy){
	std::cout<<BB<<" ScavTrap Copy constructor."<<W<<std::endl;
	this->setName(copy.getName());
	this->setAttack(copy.getAttack());
	this->setEnergy(copy.getEnergy());
	this->setHit(copy.getHit());
}	

ScavTrap &ScavTrap::operator=(const ScavTrap &copy){
	std::cout<<BB<<" ScavTrap Assignment operand."<<W<<std::endl;
/* 	if (this != &copy)
	{
	} */
	return (*this);
}

// Attacks a target. This action costs one energy point.
void ScavTrap::attack(const std::string& target){
	if (this->checkHitAndEnergy() == false)
		return ;
	std::cout<<" ScavTrap "<<this->getName()<<" attacks "
	<<target<<", causing "<<this->getAttack()<<" points of damage"
	<<std::endl;
	this->setEnergy(this->getEnergy() - 1);
}