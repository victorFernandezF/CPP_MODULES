/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:08:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/08 18:58:15 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout<<Y<<" FragTrap Default constructor."<<W<<std::endl;
}	
FragTrap::FragTrap(std::string name){
	std::cout<<Y<<" FragTrap Constructor with name."<<W<<std::endl;
	this->setName(name);
}

FragTrap::~FragTrap(){
	std::cout<<Y<<" FragTrap Destructor."<<W<<std::endl;
}

FragTrap::FragTrap(FragTrap &copy){
	std::cout<<Y<<" FragTrap Copy constructor."<<W<<std::endl;
	this->setName(copy.getName());
	this->setAttack(copy.getAttack());
	this->setEnergy(copy.getEnergy());
	this->setHit(copy.getHit());
}

void FragTrap::highFivesGuys(void){
	std::cout<<Y<<" FragTrap HIGHT FIVE."<<W<<std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy){
	std::cout<<Y<<" FragTrap Assignment operand."<<W<<std::endl;
/* 	if (this != &copy)
	{
	} */
	return (*this);
}

// Attacks a target. This action costs one energy point.
void FragTrap::attack(const std::string& target){
	if (this->checkHitAndEnergy() == false)
		return ;
	std::cout<<" FragTrap "<<this->getName()<<" attacks "
	<<target<<", causing "<<this->getAttack()<<" points of damage"
	<<std::endl;
	this->setEnergy(this->getEnergy() - 1);
}