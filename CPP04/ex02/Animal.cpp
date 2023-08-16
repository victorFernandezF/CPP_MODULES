/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:23:26 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 13:50:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

Animal::Animal(){
	std::cout<<"Animal constructor called"<<std::endl;
}

Animal::Animal(std::string type): _type(type){
	std::cout<<B<<"Animal constructor called"<<W<<std::endl;
}

Animal::Animal(Animal &copy){
	this->_type = copy._type;
}	

Animal &Animal::operator=(const Animal &copy){
	std::cout<<B<<"Animal Assignment operand."<<W<<std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

Animal::~Animal(){
	std::cout<<"Animal Destructor."<<std::endl;
}
