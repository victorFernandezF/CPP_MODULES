/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/09 12:30:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout<<BM<<" ◉ -- [TEST 1] -- ◉"<<std::endl
	<<GR<<"	This test only instances an object from each class and prints "<<std::endl
	<<"	their statuses. Just to see that each one gets "
	<<"te correct values."<<std::endl<<std::endl;
	{
		ClapTrap clap("CLAPPY");
		ScavTrap scav("SCAVY");
		FragTrap frag("FRAGGY");
		clap.printStatus();
		scav.printStatus();
		frag.printStatus();
	}
 	std::cout<<std::endl
	<<"___________________________________"<<std::endl
	<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST 2] -- ◉"<<std::endl
	<<GR<<"	This test instances an object from the class: FragTrap "<<std::endl
	<<"	and does some actions."<<std::endl<<std::endl;
	{
		FragTrap frag("FRAGGY");
		frag.printStatus();
		frag.attack("Pepito");
		frag.attack("Juanito");
		frag.highFivesGuys();
		frag.takeDamage(20);
		frag.beRepaired(5);
		frag.printStatus();
	}
	return 0;
}
