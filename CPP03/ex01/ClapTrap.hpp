/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:52:51 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 13:45:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define R	"\x1B[31m"
# define GR	"\x1B[90m"
# define G	"\x1B[32m"
# define BG	"\x1B[92m"
# define BB	"\x1B[94m"
# define Y	"\x1B[33m"
# define B	"\x1B[36m"
# define W	"\x1B[0m"
# define BY	"\x1B[93m"
# define BM	"\x1B[95m"
# define BR	"\x1B[0;95m"

class ClapTrap{
	private:
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
		
		std::string getName(void); 			
		unsigned int getHit(void); 			
		unsigned int getEnergy(void); 			
		unsigned int getAttack(void); 			
		
		bool checkHitAndEnergy(std::string action, int flag);
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