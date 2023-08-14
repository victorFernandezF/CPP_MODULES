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
	std::cout<<Y<<"WrongCat constructor called"<<W<<std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(std::string type){
	std::cout<<Y<<"WrongCat constructor called"<<W<<std::endl;
	this->setType(type);
}

WrongCat::WrongCat(WrongCat &copy){
	//this->_type = copy._type;
}	

WrongCat &WrongCat::operator=(const WrongCat &copy){
	std::cout<<Y<<"WrongCat Assignment operand."<<W<<std::endl;
	if (this != &copy)
		this->setType(copy._type);
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout<<Y<<"WrongCat Destructor."<<W<<std::endl;
}

void WrongCat::makeSound() const{	
	std::cout<<"Aaaaaa"<<std::endl;
}