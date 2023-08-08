/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:59:23 by victofer          #+#    #+#             */
/*   Updated: 2023/08/08 18:39:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"


class ScavTrap: public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &copy);	
		ScavTrap &operator=(const ScavTrap &copy);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
};

#endif