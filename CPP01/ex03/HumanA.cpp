/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:09:32 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 10:09:34 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string hName, Weapon &weapon): _name(hName), _weapon(weapon){
}

HumanA::~HumanA(void){}

void HumanA::attack(void){
	std::cout<<this->_name<<" attacks with their ";
	std::cout<<*this->_weapon.getType()<<std::endl;
}
