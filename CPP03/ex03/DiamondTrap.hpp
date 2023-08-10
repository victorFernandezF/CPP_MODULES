/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:48:01 by victofer          #+#    #+#             */
/*   Updated: 2023/08/10 18:16:35 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap 
{
	private:
		std::string _name;
	public:
		DiamondTrap();	
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &copy);	
		DiamondTrap &operator=(const DiamondTrap &copy);	
		~DiamondTrap();
		void whoAmI();
}; 

#endif