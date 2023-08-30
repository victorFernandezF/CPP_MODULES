/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:55:36 by victofer          #+#    #+#             */
/*   Updated: 2023/08/30 10:53:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"){
	
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
	std::cout<<BY<<"\nWhoAmI?\n"<<W<<"  I am DiamondTrap "<<this->_name<<"\n"
	<<"  My ClapTrap name is "<<ClapTrap::getName()<<W<<std::endl;
}
