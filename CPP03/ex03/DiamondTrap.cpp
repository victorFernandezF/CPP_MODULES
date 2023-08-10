/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:55:36 by victofer          #+#    #+#             */
/*   Updated: 2023/08/10 18:16:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"){
	
	this->_name = "Pepe";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout<<"DiamondClap constructor"<<std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"){
	
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout<<"DiamondClap constructor with name"<<std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout<<"DiamondClap destructor"<<std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout<<"Diamond: "<<this->_name<<std::endl;
	std::cout<<"ClapTrap: "<<ClapTrap::_name<<std::endl;
}
