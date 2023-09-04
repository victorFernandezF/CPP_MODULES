/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:23:26 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 13:50:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout<<"AAnimal constructor called"<<std::endl;
}

AAnimal::AAnimal(std::string type): _type(type){
	std::cout<<B<<"AAnimal constructor called"<<W<<std::endl;
}

AAnimal::AAnimal(AAnimal &copy){
	this->_type = copy._type;
}	

AAnimal &AAnimal::operator=(const AAnimal &copy){
	std::cout<<B<<"AAnimal Assignment operand."<<W<<std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

AAnimal::~AAnimal(){
	std::cout<<"AAnimal Destructor."<<std::endl;
}

void AAnimal::setType(std::string type){
	this->_type = type;
}
std::string AAnimal::getType(void) const{
	return (this->_type);
}

void AAnimal::makeSound() const{}