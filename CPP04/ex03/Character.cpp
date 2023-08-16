/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:11:46 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 19:13:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){}
Character::~Character(){}
std::string const &Character::getName() const{} 
void Character::equip(AMateria* m){}
void Character::unequip(int idx){}
void Character::use(int idx, ICharacter& target){}