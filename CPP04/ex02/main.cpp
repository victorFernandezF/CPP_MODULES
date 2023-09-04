/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/04 13:38:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void leaks(void)
{
	std::cout<<M<<" -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex02");
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
	printTestHeaders(1, TEST1, 0);
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		std::cout<<BY<<" ... Deleting ..."<<W<<std::endl;		
		delete j;//should not create a leak
		delete i;
	}
	printTestHeaders(2, TEST2, 1);
	{
		int maximun = 4;
		const AAnimal *animal[maximun];
		for (int i = 0; i < maximun; i++)
		{
			if (i % 2 == 0)
			{
				std::cout<<G;
				animal[i] = new Dog();
				std::cout<<W;
			}
			else
			{
				std::cout<<Y;
				animal[i] = new Cat();
				std::cout<<W;
			}
			std::cout<<std::endl;
		}
		std::cout<< " -- OK: NOW WE WILL DELETE DOGS AND CATS :( --"<<std::endl;
		for (int i = 0; i < maximun; i++)
		{
			if (i % 2 == 0)
				std::cout<<G;
			else
				std::cout<<Y;
			delete(animal[i]);
			std::cout<<std::endl;
		}
	}
	printTestHeaders(3, TEST3, 1);
	{
		const Cat *cats[2];
		std::cout<<BC<<" * Creating 'cat 1'"<<W<<std::endl;
		cats[0] = new Cat();
		std::cout<<BC<<"\n * Calling cat 1 make sound function "<<W<<std::endl;
		cats[0]->makeSound();
		std::cout<<BC<<"\n *Creating cat 2 (copy of cat 1)"<<W<<std::endl;;
		cats[1] = new Cat(*cats[0]);
		std::cout<<BC<<"\n * Deleting cat 1"<<W<<std::endl;
		delete(cats[0]);
		std::cout<<BC<<"\n * Cat 2, are you here? "<<W<<std::endl;
		cats[1]->makeSound();
		std::cout<<BC<<"\n * It is alive!! That means the copy works fine \n"
		<<"  Now is time to delete cat 2.\n"<<W<<std::endl;
		delete(cats[1]);
		std::cout<<std::endl;
	}
	return 0;
}
