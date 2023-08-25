/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/25 10:56:31 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex02");
}

void printTestHeaders(int test, std::string testh, int line){
	if (line == 1)
		std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST "<<test<<"] -- ◉"<<std::endl
	<<BB<<testh<<W<<std::endl<<std::endl;
}

int main(void)
{
	atexit(leaks);
	printTestHeaders(1, TEST1, 0);
	{
		Bureaucrat	*buro = new Bureaucrat("Pepe", 70);
		Bureaucrat	*buro2 = new Bureaucrat("Anselmo", 27);
		AForm	*form = new PresidentialPardonForm("ABC");

		buro2->executeForm(*form);
		buro->signForm(*form);
		//std::cout<<*form<<std::endl;
		//std::cout<<*buro<<std::endl;
		buro->executeForm(*form);
		buro2->executeForm(*form);
		delete buro;
		delete buro2;
		delete form;
	}	
	printTestHeaders(2, TEST2, 1);
	{
		Bureaucrat	*buro = new Bureaucrat("Pepe", 1);
		AForm	*form = new RobotomyRequestForm("Robotin");

		std::cout<<*buro<<std::endl;
		std::cout<<*form<<std::endl;
		buro->signForm(*form);
		std::cout<<*form<<std::endl;
		buro->executeForm(*form);
		delete buro;
		delete form;
	}
	printTestHeaders(3, TEST3, 1);
	{
		
	}
	return 0;
}
