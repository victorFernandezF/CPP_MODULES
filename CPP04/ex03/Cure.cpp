/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:16:15 by victofer          #+#    #+#             */
/*   Updated: 2023/08/17 13:16:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure(): _type("Cure"){}
Cure::Cure(Cure const &copy){
	if (this != &copy)
		*this = copy;
}

Cure &Cure::operator=(const Cure  &copy){
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

std::string const &Cure::getType() const {
	return (this->_type);
}

Cure* Cure::clone() const {
	Cure *newCure = new Cure();
	return (newCure);
}
/* void Cure::use(ICharacter& target){
	std::cout<<"* shoots an Cure bolt at "<<target.getName()<<" *"<<std::endl;
} */
