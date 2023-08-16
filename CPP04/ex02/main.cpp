/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 13:23:36 by victofer         ###   ########.fr       */
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

void testHeaderPrinter(int testNb)
{
	if (testNb == 1)
	{
		std::cout<<std::endl<<BM<<"◉ -- [TEST 1] -- ◉"<<std::endl
		<<BB<<" This is the subject example. It will creates a Cat, "<<std::endl
		<<" and a Dog. Then they will be deleted (without leaks)."<<W<<std::endl<<std::endl;
	}
	if (testNb == 2)
	{
		std::cout<<std::endl
		<<W<<"___________________________________"<<std::endl
		<<std::endl;
		std::cout<<std::endl<<BM<<"◉ -- [TEST 2] -- ◉"<<std::endl
		<<BB<<" Now we are going to create an array of animals."<<std::endl
		<<" One half will be cats and the other dogs. Then each"<<std::endl
		<<" one will be deleted (no leaks)"<<std::endl
		<<W<<std::endl;
	}
	if (testNb == 3)
	{
		std::cout<<std::endl
		<<W<<"___________________________________"<<std::endl
		<<std::endl;
		std::cout<<std::endl<<BM<<"◉ -- [TEST 3] -- ◉"<<std::endl
		<<BB<<" Testing deep copy."<<std::endl
		<<W<<std::endl;
	}
}

int main(void)
{
	atexit(leaks);
	testHeaderPrinter(1);
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	testHeaderPrinter(2);
	{
		int maximun = 6;
		const Animal *animal[maximun];
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
	testHeaderPrinter(3);
	{
		const Cat *cats[2];
		std::cout<<BB<<" *We created one cat 'cat 1'"<<W<<std::endl;
		cats[0] = new Cat();
		std::cout<<BB<<"\n *What does cat 1 say? "<<W<<std::endl;
		cats[0]->makeSound();
		std::cout<<BB<<"\n *Now we created a new cat 'cat 2' that is a copy "
		<<"of cat 1."<<W<<std::endl;
		cats[1] = new Cat(*cats[0]);
		std::cout<<BB<<"\n *We are goint to delete cat 1"<<W<<std::endl;
		delete(cats[0]);
		std::cout<<BB<<"\n *What does cat 2 say? "<<W<<std::endl;
		cats[1]->makeSound();
		std::cout<<BB<<"\n *It is alive!! That means the copy works fine \n"
		<<" Now is time to delete cat 2.\n"<<W<<std::endl;
		delete(cats[1]);
		std::cout<<std::endl;
	}
	return 0;
}
