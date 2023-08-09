/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/09 12:39:36 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout<<std::endl<<BM<<"◉ -- [TEST 1] -- ◉"<<std::endl
	<<GR<<"	This test instances an object from the class: ClapTrap "<<std::endl
	<<"	and does some actions."<<std::endl<<std::endl;
	{
		ClapTrap claptrap("MAQUINITA");	
		claptrap.printStatus();
		claptrap.attack("juan");
		claptrap.takeDamage(4);
		claptrap.beRepaired(5);
		claptrap.printStatus();
		claptrap.attack("Pepe");
	}
	std::cout<<std::endl
	<<"___________________________________"<<std::endl
	<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST 2] -- ◉"<<std::endl
	<<GR<<"	This test instances an object from the class: ClapTrap "<<std::endl
	<<"	and does some actions."<<std::endl<<std::endl;
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
