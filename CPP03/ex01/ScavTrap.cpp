/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:08:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/09 11:10:36 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout<<BB<<" ScavTrap Default constructor."<<W<<std::endl;
	this->setName("Default");
	this->setHit(100);
	this->setEnergy(50);
	this->setAttack(20);
}	

ScavTrap::ScavTrap(std::string name){
	std::cout<<BB<<" ScavTrap constructor with name."<<W<<std::endl;
	this->setName(name);
	this->setHit(100);
	this->setEnergy(50);
	this->setAttack(20);
}


ScavTrap::ScavTrap(ScavTrap &copy){
	std::cout<<BB<<" ScavTrap Copy constructor."<<W<<std::endl;
	this->setName(copy.getName());
	this->setAttack(copy.getAttack());
	this->setEnergy(copy.getEnergy());
	this->setHit(copy.getHit());
}	

ScavTrap &ScavTrap::operator=(const ScavTrap &copy){
	ScavTrap aux;
	aux = copy;
	std::cout<<BB<<" cavTrap Assignment operand."<<W<<std::endl;
	if (this != &copy)
	{
		this->setName(aux.getName());
		this->setHit(aux.getHit());
		this->setAttack(aux.getAttack());
		this->setEnergy(aux.getEnergy());
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout<<BB<<" ScavTrap Destructor."<<W<<std::endl;
}

// Attacks a target. This action costs one energy point.
void ScavTrap::attack(const std::string& target){
	if (this->checkHitAndEnergy("attack", 0) == false)
		return ;
	std::cout<<" ScavTrap "<<this->getName()<<" attacks "
	<<target<<", causing "<<this->getAttack()<<" points of damage"
	<<std::endl;
	std::cout<<R<<" This action costs 1 energy point."<<W<<std::endl;
	this->setEnergy(this->getEnergy() - 1);
}

void ScavTrap::guardGate(){
	std::cout<<" ScavTrap "<<this->getName()
	<<"  is now in Gate keeper mode."<<std::endl;
}