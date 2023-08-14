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
	std::cout<<Y<<"Cat constructor called"<<W<<std::endl;
	this->setType("Cat");
}

Cat::Cat(std::string type){
	std::cout<<Y<<"Cat constructor called"<<W<<std::endl;
	this->setType(type);
}

Cat::Cat(Cat &copy){
	//this->_type = copy._type;
}	

Cat &Cat::operator=(const Cat &copy){
	std::cout<<Y<<"Cat Assignment operand."<<W<<std::endl;
	if (this != &copy)
		this->setType(copy._type);
	return (*this);
}

Cat::~Cat(){
	std::cout<<Y<<"Cat Destructor."<<W<<std::endl;
}

void Cat::makeSound()const{	
	std::cout<<"Meaw Meaw"<<std::endl;
}