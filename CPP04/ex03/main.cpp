/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:42:11 by victofer          #+#    #+#             */
/*   Updated: 2023/09/04 10:46:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void leaks(void)
{
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex03");
}

void printTestHeaders(int test, std::string testh, int line){
	if (line == 1)
		std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST "<<test<<" ] -- ◉"<<std::endl
	<<BB<<testh<<W<<std::endl;
}

int main(void)
{
	atexit(leaks);
	printTestHeaders(1, TEST1, 1);
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	printTestHeaders(2, TEST2, 1);
	{
		AMateria *ice = new Ice();
		AMateria *cure = new Cure();
		
		ICharacter* me = new Character("me");
		
		me->equip(ice);
		me->equip(cure);
		me->equip(ice);
		me->printSlots();
		std::cout<<BC<<"\n  *Unequip last materia* "<<W<<std::endl;
		me->unequip(2);
		me->printSlots();
		std::cout<<std::endl;
		
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		//delete ice_2;
	}
	return 0;
}
 