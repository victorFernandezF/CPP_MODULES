/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:23:26 by victofer          #+#    #+#             */
/*   Updated: 2023/08/10 19:48:05 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout<<C<<"WrongAnimal constructor called"<<W<<std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type){
	std::cout<<C<<"WrongAnimal constructor called"<<W<<std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &copy){
	this->_type = copy._type;
}	

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy){
	std::cout<<C<<"WrongAnimal Assignment operand."<<W<<std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout<<C<<"WrongAnimal Destructor."<<W<<std::endl;
}

void WrongAnimal::setType(std::string type){
	this->_type = type;
}
std::string WrongAnimal::getType(void) const{
	return (this->_type);
}

void WrongAnimal::makeSound() const{}