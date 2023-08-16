/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 18:34:48 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout<<std::endl<<BM<<"◉ -- [TEST 1] -- ◉"<<std::endl
	<<BB<<" This test instances an object from the class: ClapTrap "<<std::endl
	<<" and does some actions."<<std::endl<<std::endl;
	{
		ClapTrap clap("Clappy");
		clap.printStatus();
		clap.attack("ABC");
		clap.takeDamage(5);
		clap.beRepaired(1);
		clap.printStatus();
	}
	std::cout<<std::endl
	<<"___________________________________"<<std::endl
	<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- TEST 2 -- ◉"<<std::endl
	<<BB<<" This test instances an object from the class: ScavTrap "<<std::endl
	<<" and does some actions."<<std::endl<<std::endl;
	{
		ScavTrap scav("Scavy");
		scav.printStatus();
		scav.printStatus();
		scav.guardGate();
		scav.attack("ABC");
		scav.takeDamage(5);
		scav.beRepaired(1);
		scav.printStatus();
	}
	return 0;
}
