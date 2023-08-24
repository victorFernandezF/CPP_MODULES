/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:08:15 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 10:09:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout<<C<<"Constructor called"<<W<<std::endl;
}

Zombie::~Zombie(void){
    std::cout<<BR<<this->_name<<" has been destroyed"<<W<<std::endl;
}

void Zombie::setName(std::string name){
    this->_name = name;
}

void Zombie::announce(void){
    std::cout<<G<<this->_name<<":  BraiiiiiiinnnzzzZ..."<<W<<std::endl;
}
