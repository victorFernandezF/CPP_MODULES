/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:47:52 by victofer          #+#    #+#             */
/*   Updated: 2023/08/17 12:59:05 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice(): _type("ice") {
}

Ice::~Ice(){
}

Ice::Ice(Ice const &copy){
	if (this != &copy)
		*this = copy;
}

Ice &Ice::operator=(const Ice &copy){
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

std::string const & Ice::getType() const{
	return (this->_type);
}

AMateria* Ice::clone() const {
	Ice *newIce = new Ice();
	return (newIce);
}

void Ice::use(ICharacter& target){
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}
