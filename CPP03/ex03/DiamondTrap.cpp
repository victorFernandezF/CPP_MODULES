/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:55:36 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 13:56:21 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"){
	
	this->_name = "Pepe";
	this->setHit(FragTrap::getHit());
	this->setEnergy(ScavTrap::getEnergy());
	this->setAttack(FragTrap::getAttack());
	std::cout<<"DiamondClap constructor"<<std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"){
	
	this->_name = name;
	this->setHit(FragTrap::getHit());
	this->setEnergy(ScavTrap::getEnergy());
	this->setAttack(FragTrap::getAttack());
	std::cout<<"DiamondClap constructor with name"<<std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout<<"DiamondClap destructor"<<std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout<<"Diamond: "<<this->_name<<std::endl;
	std::cout<<"ClapTrap: "<<ClapTrap::getName()<<std::endl;
}
