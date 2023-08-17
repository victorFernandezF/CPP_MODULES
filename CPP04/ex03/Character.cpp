/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:25:31 by victofer          #+#    #+#             */
/*   Updated: 2023/08/17 19:16:01 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name):  _name(name), _maxItems(4){
	for (int i = 0; i < this->_maxItems; i++)
		this->_slots[i] = nullptr;
}

Character::Character(const Character &copy){
	this->_maxItems = copy._maxItems;
	this->_name = copy._name;
	if (this->_slots[0] != nullptr)
		for (int i = 0; i < this->_maxItems; i++)
			delete this->_slots[i];
	for (int i = 0; i < this->_maxItems; i++)
		this->_slots[i] = copy._slots[i];
}

Character::~Character(){
	if (this->_slots[0] != nullptr)
		for (int i = 0; i < this->_maxItems; i++)
			delete this->_slots[i];
}

Character &Character::operator=(const Character &copy){
	this->_maxItems = copy._maxItems;
	this->_name = copy._name;
	if (this->_slots[0] != nullptr)
		for (int i = 0; i < this->_maxItems; i++)
			delete(this->_slots[i]);
	for (int i = 0; i < this->_maxItems; i++)
		this->_slots[i] = copy._slots[i];
	return (*this);
}
std::string const &Character::getName() const {
	return (this->_name);
}

int Character::_findFreeSlot(){
	for (int i = 0; i < this->_maxItems; i++)
		if (this->_slots[i] == nullptr)
			return (i);
	return (-1);
}

void Character::equip(AMateria* m){
	(void)m;
	int freeSlot = this->_findFreeSlot();
	if (freeSlot == -1)
		return ;
	this->_slots[freeSlot] = m;
	std::cout<<"Free Slot: "<<freeSlot<<std::endl;
}

/*void Character::unequip(int idx){}
void Character::use(int idx, Character& target){} */