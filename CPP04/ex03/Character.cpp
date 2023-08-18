/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:25:31 by victofer          #+#    #+#             */
/*   Updated: 2023/08/18 13:40:53 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name):  _name(name), _maxItems(4){
	for (int i = 0; i < this->_maxItems; i++)
		this->_slots[i] = 0;
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
	for (int i = 0; i < this->_maxItems; i++)
		if (this->_slots[i])
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

// F U N C T I O N S

int Character::_findFreeSlot(){
	for (int i = 0; i < this->_maxItems; i++)
		if (this->_slots[i] == nullptr)
			return (i);
	return (-1);
}

void Character::printSlots()
{
	std::cout<<BY<<"SLOTS STATUS"<<W<<std::endl;
	for (int i = 0; i < this->_maxItems; i++)
		if (this->_slots[i] != nullptr)
			std::cout<<"  ["<<BB<<i<<W<<"] "<<this->_slots[i]->getType()
			<<std::endl;
}

void Character::equip(AMateria* m){
	if (m == nullptr)
	{
		std::cout<<BR<<"No materia?"<<std::endl;
		return ;	
	}
	int freeSlot = this->_findFreeSlot();
	if (freeSlot == -1)
	{
		std::cout<<R<<"All Slots are full"<<std::endl;
		return ;
	}
	this->_slots[freeSlot] = m;
	std::cout<<G<<m->getType()<<" equiped on slot "<<freeSlot<<W<<std::endl;
}

void Character::unequip(int idx){
	AMateria *aux;
	if (idx < 0 || idx >= this->_maxItems || idx == this->_findFreeSlot())
	{
		std::cout<<BR<<"Index not found."<<std::endl;
		return ;
	}
	aux = this->_slots[idx];
	for (int i = idx; i < this->_maxItems -1; i++)
	{
		this->_slots[i] = this->_slots[i +1];
		this->_slots[i + 1] = nullptr;
	}
	std::cout<<G<<aux->getType()<<" unequiped from slot "<<idx<<W<<std::endl;
	
}
void Character::use(int idx, ICharacter& target){
	this->_slots[idx]->use(target);
}