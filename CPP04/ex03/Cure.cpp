/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:58:03 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 19:02:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): _type("Cure"){}
Cure::~Cure(){}
Cure::Cure(const Cure &copy){
	if (this != &copy)
		this->_type = copy._type;
}
//Cure &Cure::operator=(const Cure &copy){}
void Cure::use(ICharacter &character){
	std::cout<<"* heals "<<character<<"'s wounds *"<<std::endl;
}