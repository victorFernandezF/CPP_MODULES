/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:52:51 by victofer          #+#    #+#             */
/*   Updated: 2023/08/31 17:49:27 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include "colours.h"


class ClapTrap{
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	
	public:
		ClapTrap();	
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &copy);	
		ClapTrap &operator=(const ClapTrap &copy);	
		~ClapTrap();
		
		std::string getName(void) const; 			
		unsigned int getHit(void) const; 			
		unsigned int getEnergy(void) const; 			
		unsigned int getAttack(void) const; 			
		
		bool checkHitAndEnergy(std::string action, int flag);
		void printStatus(void);
		void printMessage(std::string action, std::string target, int amount);

		void setName(std::string name);
		void setHit(int hit);
		void setEnergy(int energy);			
		void setAttack(int attack);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif