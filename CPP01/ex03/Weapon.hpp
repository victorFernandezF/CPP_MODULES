/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:10:14 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 10:10:17 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string* getType(void);
		void setType(std::string type);
};

#endif