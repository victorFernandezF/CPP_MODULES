/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/29 13:18:21 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		AForm* ppf;
		
		try{	
			ppf = someRandomIntern.makeForm("Presidential Pardon", "Bender");
			buro = new Bureaucrat("Bureaucrator", 2);
			buro->signForm(*ppf);
			buro->executeForm(*ppf);
			std::cout<<"\n";
		}catch(std::exception &e){
			std::cout<<BR<<"Error: "<<e.what()<<W<<std::endl;
		}
		if (ppf)
			delete ppf;
		if (buro)
			delete buro;
	}
	printTestHeaders(2, TEST2, 1);
	{
		Intern someRandomIntern;
		Bureaucrat *buro;
		AForm* rrf;
		
		try{	
			rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
			buro = new Bureaucrat("Bureaucrator", 2);
			buro->signForm(*rrf);
			buro->executeForm(*rrf);
			std::cout<<"\n";
		}catch(std::exception &e){
			std::cout<<BR<<"Error: "<<e.what()<<W<<std::endl;
		}
		if (rrf)
			delete rrf;
		if (buro)
			delete buro;	
	}
	printTestHeaders(3, TEST3, 1);
	{
		Intern someRandomIntern;
		Bureaucrat *buro;
		AForm* scf;
		
		try{	
			scf = someRandomIntern.makeForm("shruBerry CreatIon", "Bender");
			buro = new Bureaucrat("Bureaucrator", 2);
			buro->signForm(*scf);
			buro->executeForm(*scf);
			std::cout<<"\n";
		}catch(std::exception &e){
			std::cout<<BR<<"Error: "<<e.what()<<W<<std::endl;
		}
		if (scf)
			delete scf;
		if (buro)
			delete buro;
	}
	printTestHeaders(4, TEST4, 1);
	{
		Intern someRandomIntern;
		Bureaucrat *buro;
		AForm* hdf;
		
		try{	
			hdf = someRandomIntern.makeForm("house destruction", "Bender");
			buro = new Bureaucrat("Bureaucrator", 2);
			buro->signForm(*hdf);
			buro->executeForm(*hdf);
			std::cout<<"\n";
		}catch(std::exception &e){
			std::cout<<BR<<"Error: "<<e.what()<<W<<std::endl;
		}
	}
	return 0;
}
