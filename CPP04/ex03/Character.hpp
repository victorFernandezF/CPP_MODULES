/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:20:31 by victofer          #+#    #+#             */
/*   Updated: 2023/08/17 18:56:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "colours.h"
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_slots[4];
		int _maxItems;
		int _findFreeSlot();
	public:
		Character(std::string name);
		Character(const Character &copy);
		~Character();
		Character &operator=(const Character &copy);
		std::string const & getName() const;
 		void equip(AMateria* m);
/*		void unequip(int idx);
		void use(int idx, Character& target); */
};
# endif