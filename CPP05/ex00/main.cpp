/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 11:20:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void leaks(void)
{
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
}

void printTestHeaders(int test){
	if (test == 1)
		std::cout<<std::endl<<BM<<"◉ -- [TEST 1] -- ◉"<<std::endl
		<<BB<<TEST1<<W<<std::endl<<std::endl<<std::endl;
	if (test == 2)
		std::cout<<std::endl<<BM<<"◉ -- [TEST 2] -- ◉"<<std::endl
		<<BB<<TEST2<<W<<std::endl<<std::endl;
	if (test == 3)
		std::cout<<std::endl<<BM<<"◉ -- [TEST 3] -- ◉"<<std::endl
		<<BB<<TEST3<<W<<std::endl<<std::endl;
}

int main(void)
{
	atexit(leaks);
	printTestHeaders(1);
	{
		Bureaucrat buro("pepe", 27);
		std::cout<<buro<<std::endl;
	}
	std::cout<<"___________________________________\n"<<std::endl;
	printTestHeaders(2);
	{
		Bureaucrat *buro;
		
		try{
			buro = new Bureaucrat("pepe", 180);
			std::cout<<buro<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
	}
	std::cout<<"___________________________________\n"<<std::endl;
	printTestHeaders(3);
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
