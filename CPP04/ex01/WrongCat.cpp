/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:23:26 by victofer          #+#    #+#             */
/*   Updated: 2023/08/10 18:32:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
	Brain *createdBrain = new Brain();
	this->setType("WrongCat");
	this->_brain = createdBrain;
	std::cout<<"WrongCat constructor called"<<std::endl;
}

WrongCat::WrongCat(std::string type){
	std::cout<<"WrongCat constructor called"<<std::endl;
	this->setType(type);
}

WrongCat::WrongCat(const WrongCat &copy): Animal(){
	Brain *createdBrain = new Brain();
	this->_type = copy._type;
	this->_brain = createdBrain;
	std::cout<<"WrongCat Copy constructor called"<<std::endl;	
}	

WrongCat &WrongCat::operator=(const WrongCat &copy){
	std::cout<<"WrongCat Assignment operand."<<std::endl;
	if (this != &copy){
		Brain *createdBrain = new Brain();
		this->_type = copy._type;
		this->_brain = createdBrain;
	}
	return (*this);
}

WrongCat::~WrongCat(){
	delete(this->_brain);
	std::cout<<"WrongCat Destructor."<<std::endl;
}

void WrongCat::makeSound()const{	
	std::cout<<"Meaw Meaw"<<std::endl;
}