/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/22 12:39:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
	<<BB<<testh<<W<<std::endl;
}

int main(void)
{
	atexit(leaks);
	printTestHeaders(1, TEST1, 0);
	{
		Bureaucrat	*buro = new Bureaucrat("Evaristo", 145);
		AForm	*form = new ShrubberyCreationForm("Antonio");

		std::cout<<"GENERAL INFO"<<std::endl;
		std::cout<<*buro<<std::endl;
		std::cout<<*form<<std::endl;
		std::cout<<std::endl;
		buro->signForm(*form);
		buro->executeForm(*form);
		std::cout<<BB<<" * Of course not.\n  But we are going to increment "
		<<buro->getName()<<"'s grade 8 times. to make it posible."<<W<<std::endl;
		for (int i = 0; i < 8; i++)
			buro->incrementGrade();
		std::cout<<*buro<<std::endl;
		std::cout<<BB<<" * Come on "<<buro->getName()<<" try again"<<W<<std::endl;
		buro->executeForm(*form);
		
		delete buro;
		delete form;
	}
 	printTestHeaders(2, TEST2, 1);
	{
		Bureaucrat	*buro = new Bureaucrat("Maria", 1);
		AForm	*form = new RobotomyRequestForm("Marvin");

		std::cout<<"GENERAL INFO"<<std::endl;
		std::cout<<*buro<<std::endl;
		std::cout<<*form<<std::endl;
		std::cout<<std::endl;
		buro->executeForm(*form);
		buro->signForm(*form);
		buro->executeForm(*form);
		delete buro;
		delete form;
	}
 	printTestHeaders(3, TEST3, 1);
	{
		Bureaucrat	*buro = new Bureaucrat("Ricardo", 70);
		Bureaucrat	*buro2 = new Bureaucrat("Mortadelo", 27);
		AForm	*form = new PresidentialPardonForm("Jerry");

		std::cout<<"GENERAL INFO"<<std::endl;
		std::cout<<*buro<<std::endl;
		std::cout<<*buro2<<std::endl;
		std::cout<<*form<<std::endl;
		std::cout<<std::endl;
		buro->signForm(*form);
		buro->executeForm(*form);
		buro2->executeForm(*form);
		
		delete buro;
		delete buro2;
		delete form;
	}
	return 0;
}
