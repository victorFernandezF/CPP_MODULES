/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/10 20:01:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void leaks(void)
{
	system("leaks -q ex00");
}

int main(void)
{
	atexit(leaks);
	std::cout<<std::endl<<BM<<"◉ -- [TEST 1] -- ◉"<<std::endl
	<<GR<<"	"<<W<<std::endl<<std::endl;
	{
		WrongAnimal* meta = new WrongAnimal();
		Animal* j = new Dog();
		WrongCat* i = new WrongCat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout<< "cat -> ";
		i->makeSound(); //will output the cat sound!
		std::cout<< "dog -> ";
		j->makeSound();
		meta->makeSound();
		delete(i);
		delete(j);
		delete(meta);

	}
	std::cout<<std::endl
	<<"___________________________________"<<std::endl
	<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST 2] -- ◉"<<std::endl
	<<GR<<"	"<<std::endl<<std::endl;
	{

	}
	return 0;
}
