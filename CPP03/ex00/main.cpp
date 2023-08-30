/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/30 10:24:54 by victofer         ###   ########.fr       */
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
		ClapTrap claptrap("MAQUINITA");	
		claptrap.printStatus();
		claptrap.attack("juan");
		claptrap.takeDamage(4);
		claptrap.beRepaired(5);
		claptrap.printStatus();
		claptrap.attack("Pepe");
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
