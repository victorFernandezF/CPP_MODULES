/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:09:54 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 10:09:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string humanName);
		~HumanB(void);
		void setWeapon(Weapon &weapon);
		void attack(void);
};

#endif