/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:42:11 by victofer          #+#    #+#             */
/*   Updated: 2023/08/18 13:13:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void leaks(void)
{
	std::cout<<M<<" -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex03");
}

int main(void)
{
	atexit(leaks);
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	
	ICharacter* me = new Character("me");
	
	me->equip(ice);
	me->equip(cure);
	me->equip(ice);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	

	delete bob;
	delete me;

	return 0;
 }
 