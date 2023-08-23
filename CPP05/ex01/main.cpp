/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 13:23:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex01");
}

void printTestHeaders(int test, std::string testh, int line){
	if (line == 1)
		std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST "<<test<<" ] -- ◉"<<std::endl
	<<BB<<testh<<W<<std::endl<<std::endl;
}

int main(void)
{
	atexit(leaks);
	printTestHeaders(1, TEST1, 0);
	{
		Bureaucrat *buro = new Bureaucrat("pepe", 5);
		Form *form = new Form("form1", 6, 2);
		
		std::cout<<*buro<<std::endl;
		std::cout<<*form<<std::endl;
		buro->signForm(*form);
		delete buro;
		delete form;
	}
	
	printTestHeaders(2, TEST2, 1);
	{
		Bureaucrat *buro = new Bureaucrat("pepe", 5);
		Form *form = new Form("form1", 3, 2);
		
		std::cout<<*buro<<std::endl;
		std::cout<<*form<<std::endl;
		buro->signForm(*form);
		delete buro;
		delete form;
	}
	return 0;
}
