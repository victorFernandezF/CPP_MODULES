/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:58:03 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 19:15:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice(): _type("ice"){}
Ice::~Ice(){}
Ice::Ice(const Ice &copy){
	if (this != &copy)
		this->_type = copy._type;
}
//Ice &Ice::operator=(const Ice &copy){}
void Ice::use(ICharacter &character){
	std::cout<<"* shoots an ice bolt at "<<character<<" *"<<std::endl;
}