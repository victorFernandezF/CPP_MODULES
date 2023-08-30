/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/30 11:53:35 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void leaks(void)
{
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
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
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete(i);
		delete(j);
		delete(meta);
	}
	printTestHeaders(2, TEST2, 1);
	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* dog = new Dog();
		const WrongAnimal* cat = new WrongCat();
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		dog->makeSound(); //will output the cat sound!
		cat->makeSound();
		meta->makeSound();
		delete(dog);
		delete(cat);
		delete(meta);
	}
	return 0;
}
