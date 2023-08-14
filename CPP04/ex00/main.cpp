/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 12:24:35 by victofer         ###   ########.fr       */
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
	<<GR<<"	This is the subject example. It will creates an Animal, "<<std::endl
	<<"	a Dog and a Cat. Prints their types and prints their sounds.	"<<W<<std::endl<<std::endl;
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
	std::cout<<std::endl
	<<"___________________________________"<<std::endl
	<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST 2] -- ◉"<<std::endl
	<<GR<<"	In this case the Animal has been replaced by WrongAnimal, "<<std::endl
	<<"	and the Cat by WrongCat. Prints their types and prints their sounds.	"<<W<<std::endl<<std::endl;
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
