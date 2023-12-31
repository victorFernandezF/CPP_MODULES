/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:07:25 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 10:02:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout<<"Constructor called"<<std::endl;
}

Zombie::~Zombie(void){
    std::cout<<this->_name<<" has been destroyed"<<std::endl;
}

void Zombie::setName(std::string name){
    this->_name = name;
}

void Zombie::announce(void){
    std::cout<<this->_name<<":  BraiiiiiiinnnzzzZ..."<<std::endl;
}
