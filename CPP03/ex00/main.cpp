/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/31 10:15:39 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
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
		ClapTrap claptrap("CLAPY");	
		claptrap.printStatus();
		claptrap.attack("clap_2");
		claptrap.takeDamage(4);
		claptrap.beRepaired(5);
		claptrap.printStatus();
		claptrap.attack("clap_3");
	}
	printTestHeaders(2, TEST2, 1);
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
