/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/08 17:47:23 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		
#include "ClapTrap.hpp"

int main(void)
{
	{
		ClapTrap claptrap("MAQUINITA");

		std::cout<<BR<<" -- [TEST 1] -- "<<std::endl;
		claptrap.printStatus();
		claptrap.attack("juan");
		claptrap.printStatus();
		claptrap.takeDamage(2);
		claptrap.printStatus();
		claptrap.beRepaired(5);
		claptrap.printStatus();
		claptrap.attack("Pepe");
	}
	{
		ClapTrap claptrap;

		std::cout<<std::endl<<BR<<" -- [TEST 2] -- "<<std::endl;
		claptrap.printStatus();
		claptrap.takeDamage(15);
		claptrap.printStatus();
		claptrap.beRepaired(5);
	}
	return 0;
}
