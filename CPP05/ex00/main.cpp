/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 13:27:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
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
		Bureaucrat buro("pepe", 27);
		std::cout<<buro<<std::endl;
	}
	printTestHeaders(2, TEST2, 1);
	{
		Bureaucrat *buro;
		
		try{
			buro = new Bureaucrat("pepe", 180);
			std::cout<<buro<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
	}
	printTestHeaders(3, TEST3, 1);
	{
		Bureaucrat *buro = new Bureaucrat("pepe", 150);		
		
		std::cout<<*buro<<std::endl;

		try{
			buro->incrementGrade();
			std::cout<<G<<"incrementation Success."<<W<<std::endl;
			std::cout<<*buro<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
		try{
			buro->decrementGrade();
			std::cout<<G<<"decrementation Success."<<W<<std::endl;
			std::cout<<*buro<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
		try{
			buro->decrementGrade();
			std::cout<<G<<"decrementation Success."<<W<<std::endl;
			std::cout<<*buro<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
		delete buro; 
	}
	return 0;
}
