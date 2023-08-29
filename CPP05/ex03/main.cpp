/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/29 19:11:54 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
//#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
//#include "ShrubberyCreationForm.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex03");
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
		Intern someRandomIntern;
		Bureaucrat *buro;
		AForm* form;
		
		form = someRandomIntern.makeForm("Presidential Pardon", "Bender");
		if (form){
			buro = new Bureaucrat("Bureaucrator", 5);
			buro->signForm(*form);
			buro->executeForm(*form);
			std::cout<<"\n";
			delete form;
			delete buro;
		}
	}
	printTestHeaders(2, TEST2, 1);
	{
		Intern someRandomIntern;
		Bureaucrat *buro;
		AForm* form;
		
		
		form = someRandomIntern.makeForm("Robotomy Request", "Bender");
		if (form){
			buro = new Bureaucrat("Bureaucrator", 2);
			buro->signForm(*form);
			buro->executeForm(*form);
			std::cout<<"\n";
			delete form;
			delete buro;
		}
	}
	printTestHeaders(3, TEST3, 1);
	{
		Intern someRandomIntern;
		Bureaucrat *buro;
		AForm* form;
		
		form = someRandomIntern.makeForm("shrubbery CreatIon", "Bender");
		if (form){
			buro = new Bureaucrat("Bureaucrator", 2);
			buro->signForm(*form);
			buro->executeForm(*form);
			std::cout<<"\n";
			delete form;
			delete buro;
		}
	}
	printTestHeaders(4, TEST4, 1);
	{
		Intern someRandomIntern;
		Bureaucrat *buro;
		AForm* form;

		form = someRandomIntern.makeForm("House demolition", "Bender");
		if (form){
			buro = new Bureaucrat("Bureaucrator", 2);
			buro->signForm(*form);
			buro->executeForm(*form);
			std::cout<<"\n";
			delete form;
			delete buro;
		}
	}
	return 0;
}
