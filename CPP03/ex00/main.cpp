/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/09 11:06:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		
#include "ClapTrap.hpp"

int main(void)
{
	std::cout<<BR<<" -- [TEST 1] -- "<<std::endl<<std::endl;
	{
		ClapTrap claptrap("MAQUINITA");	
		claptrap.printStatus();
		claptrap.attack("juan");
		claptrap.takeDamage(4);
		claptrap.beRepaired(5);
		claptrap.printStatus();
		claptrap.attack("Pepe");
	}
	std::cout<<std::endl<<BR<<" -- [TEST 2] -- "<<std::endl<<std::endl;
	{
		ClapTrap claptrap;
		claptrap.printStatus();
		claptrap.takeDamage(2);
		claptrap.takeDamage(3);
		claptrap.takeDamage(5);
		claptrap.printStatus();
		claptrap.beRepaired(5);
	}
	return 0;
}
