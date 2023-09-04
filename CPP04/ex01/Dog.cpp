/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:23:26 by victofer          #+#    #+#             */
/*   Updated: 2023/08/10 18:32:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	Brain *createdBrain = new Brain();
	this->setType("Dog");
	this->_brain = createdBrain;
	std::cout<<"Dog constructor called"<<W<<std::endl;
}

Dog::Dog(std::string type){
	std::cout<<G<<"Dog constructor called"<<W<<std::endl;
	this->setType(type);
}

Dog::Dog(const Dog &copy): Animal(){
	Brain *createdBrain = new Brain();
	this->_type = copy._type;
	this->_brain = createdBrain;
	std::cout<<Y<<"Cat Copy constructor called"<<W<<std::endl;	
}	

Dog &Dog::operator=(const Dog &copy){
	std::cout<<G<<"Dog Assignment operand."<<W<<std::endl;
	if (this != &copy){
		Brain *createdBrain = new Brain();
		this->_type = copy._type;
		this->_brain = createdBrain;
	}
	return (*this);
}

Dog::~Dog(){
	delete(this->_brain);
	std::cout<<"Dog Destructor."<<std::endl;
}

void Dog::makeSound() const{	
	std::cout<<"Wof wof"<<std::endl;
}
