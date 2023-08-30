/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:52:51 by victofer          #+#    #+#             */
/*   Updated: 2023/08/30 10:19:23 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include "colours.h"


class ClapTrap{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		bool _checkHitAndEnergy(std::string action, int flag);
	
	public:
		ClapTrap();	
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &copy);	
		ClapTrap &operator=(const ClapTrap &copy);	
		~ClapTrap();
		
		std::string getName(void); 			
		unsigned int getHit(void); 			
		unsigned int getEnergy(void); 			
		unsigned int getAttack(void); 			
		
		void printStatus(void);

		void setName(std::string name);
		void setHit(int hit);
		void setEnergy(int energy);			
		void setAttack(int attack);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif