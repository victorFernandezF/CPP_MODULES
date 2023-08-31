/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/31 10:17:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex02");
}

void printTestHeaders(int test, std::string testh, int line){
	if (line == 1)
		std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST "<<test<<" ] -- ◉"<<std::endl
	<<BB<<testh<<W<<std::endl<<std::endl;
}

int main(void)
{
	atexit(leaks);
	printTestHeaders(1, TEST1, 0);
	{
		ClapTrap clap("CLAPPY");
		ScavTrap scav("SCAVY");
		FragTrap frag("FRAGGY");
		clap.printStatus();
		scav.printStatus();
		frag.printStatus();
	}
	printTestHeaders(2, TEST2, 0);
	{
		FragTrap frag("FRAGGY");
		frag.printStatus();
		frag.attack("clap_2");
		frag.attack("clap_2");
		frag.highFivesGuys();
		frag.takeDamage(20);
		frag.beRepaired(5);
		frag.printStatus();
	}
	return 0;
}
