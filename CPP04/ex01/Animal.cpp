/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:23:26 by victofer          #+#    #+#             */
/*   Updated: 2023/09/04 13:27:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal(){
	std::cout<<C<<"Animal constructor called"<<W<<std::endl;
}

// Constructor with arg
Animal::Animal(std::string type): _type(type){
	std::cout<<C<<"Animal constructor called"<<W<<std::endl;
}

// Copy constructor
Animal::Animal(Animal &copy){
	this->_type = copy._type;
}	

// Asignment operator overload.
Animal &Animal::operator=(const Animal &copy){
	std::cout<<C<<"Animal Assignment operand."<<W<<std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

// Destructor
Animal::~Animal(){
	std::cout<<C<<"Animal Destructor."<<W<<std::endl;
}

void Animal::setType(std::string type){
	this->_type = type;
}
std::string Animal::getType(void) const{
	return (this->_type);
}

void Animal::makeSound() const{}