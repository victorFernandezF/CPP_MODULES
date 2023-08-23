/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:10:08 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 10:10:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	this->setType(type);
}
Weapon::~Weapon(void){}

std::string* Weapon::getType(void){
	std::string &ref = this->_type;
	return (&ref);
}

void Weapon::setType(std::string type){
	this->_type = type;
}