/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:52:51 by victofer          #+#    #+#             */
/*   Updated: 2023/08/08 17:45:27 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define R	"\x1B[31m"
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
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	
	public:
		ClapTrap();	
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &copy);	
		ClapTrap &operator=(const ClapTrap &copy);	
		~ClapTrap();
		
		std::string getName(void); 			
		int getHit(void); 			
		int getEnergy(void); 			
		int getAttack(void); 			
		
		bool checkHitAndEnergy(void);
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