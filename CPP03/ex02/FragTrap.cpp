/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:08:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 13:50:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout<<BG<<" FragTrap Default constructor."<<W<<std::endl;
	this->setName("Default");
	this->setHit(100);
	this->setEnergy(100);
	this->setAttack(30);
}	
FragTrap::FragTrap(std::string name){
	std::cout<<BG<<" FragTrap Constructor with name."<<W<<std::endl;
	this->setName(name);
	this->setHit(100);
	this->setEnergy(100);
	this->setAttack(30);
}

FragTrap::~FragTrap(){
	std::cout<<BG<<" FragTrap Destructor."<<W<<std::endl;
}

FragTrap::FragTrap(FragTrap &copy){
	std::cout<<BG<<" FragTrap Copy constructor."<<W<<std::endl;
	this->setName(copy.getName());
	this->setAttack(copy.getAttack());
	this->setEnergy(copy.getEnergy());
	this->setHit(copy.getHit());
}

/* FragTrap &FragTrap::operator=(const FragTrap &copy){
	FragTrap aux;
	aux = copy;
	std::cout<<BG<<" FragTrap Assignment operand."<<W<<std::endl;
	if (this != &copy)
	{
		this->setName(aux.getName());
		this->setHit(aux.getHit());
		this->setAttack(aux.getAttack());
		this->setEnergy(aux.getEnergy());
	}
	return (*this);
} */

void FragTrap::highFivesGuys(void){
	std::cout<<BG<<"GIVE ME A HIGHT FIVE!!!"<<W<<std::endl;
}

// Attacks a target. This action costs one energy point.
void FragTrap::attack(const std::string& target){
	if (this->checkHitAndEnergy("attack", 0) == false)
		return ;
	std::cout<<"FragTrap "<<this->getName()<<G<<" attacks "
	<<W<<target<<", causing "<<G<<this->getAttack()<<W<<" points of damage"
	<<std::endl;
	std::cout<<R<<" *"<<W<<"This action costs "<<R<<"1"<<W<<" energy point."<<W<<std::endl;
	this->setEnergy(this->getEnergy() - 1);
}