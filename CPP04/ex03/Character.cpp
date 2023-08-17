/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:25:31 by victofer          #+#    #+#             */
/*   Updated: 2023/08/17 13:52:18 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name):  _name(name), _maxItems(4){}
Character::Character(const Character &copy){
	this->_maxItems = copy._maxItems;
	this->_name = copy._name;
	if (this->_inventory[0] != nullptr)
		for (int i = 0; i < this->_maxItems; i++)
			delete this->_inventory[i];
	for (int i = 0; i < this->_maxItems; i++)
		this->_inventory[i] = copy._inventory[i];
}

Character::~Character(){
	if (this->_inventory[0] != nullptr)
		for (int i = 0; i < this->_maxItems; i++)
			delete this->_inventory[i];
}
Character &Character::operator=(const Character &copy){
	this->_maxItems = copy._maxItems;
	this->_name = copy._name;
	if (this->_inventory[0] != nullptr)
		for (int i = 0; i < this->_maxItems; i++)
			delete(this->_inventory[i]);
	for (int i = 0; i < this->_maxItems; i++)
		this->_inventory[i] = copy._inventory[i];
	return (*this);
}
std::string const &Character::getName() const {
	return (this->_name);
}

/* void Character::equip(AMateria* m){}
void Character::unequip(int idx){}
void Character::use(int idx, Character& target){} */