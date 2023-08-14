/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 18:50:26 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void leaks(void)
{
	system("leaks -q ex01");
}

void testHeaderPrinter(int testNb)
{
	if (testNb == 1)
	{
		std::cout<<std::endl<<BM<<"◉ -- [TEST 1] -- ◉"<<std::endl
		<<GR<<" This is the subject example. It will creates a Cat, "<<std::endl
		<<" and a Dog. Then they will be deleted (without leaks)."<<W<<std::endl<<std::endl;
	}
	if (testNb == 2)
	{
		std::cout<<std::endl
		<<W<<"___________________________________"<<std::endl
		<<std::endl;
		std::cout<<std::endl<<BM<<"◉ -- [TEST 2] -- ◉"<<std::endl
		<<GR<<" Now we are going to create an array of animals."<<std::endl
		<<" One half will be cats and the other dogs. Then each"<<std::endl
		<<" one will be deleted (no leaks)"<<std::endl
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
		int maximun = 3;
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
		 std::cout<<W<<std::endl;
	} 
	return 0;
}
