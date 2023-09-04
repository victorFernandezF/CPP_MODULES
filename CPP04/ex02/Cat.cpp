/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:23:26 by victofer          #+#    #+#             */
/*   Updated: 2023/08/10 18:32:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	Brain *createdBrain = new Brain();
	this->setType("Cat");
	this->_brain = createdBrain;
	std::cout<<"Cat constructor called"<<std::endl;
}

Cat::Cat(std::string type){
	std::cout<<"Cat constructor called"<<std::endl;
	this->setType(type);
}

Cat::Cat(const Cat &copy): AAnimal(){
	Brain *createdBrain = new Brain();
	this->_type = copy._type;
	this->_brain = createdBrain;
	std::cout<<"Cat Copy constructor called"<<std::endl;	
}	

Cat &Cat::operator=(const Cat &copy){
	std::cout<<"Cat Assignment operand."<<std::endl;
	if (this != &copy){
		Brain *createdBrain = new Brain();
		this->_type = copy._type;
		this->_brain = createdBrain;
	}
	return (*this);
}

Cat::~Cat(){
	delete(this->_brain);
	std::cout<<"Cat Destructor."<<std::endl;
}

void Cat::makeSound()const{	
	std::cout<<"Meaw Meaw"<<std::endl;
}