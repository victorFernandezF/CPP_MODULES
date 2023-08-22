/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/22 19:14:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void leaks(void)
{
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
}

int main(void)
{
	atexit(leaks);
	std::cout<<std::endl<<BM<<"◉ -- [TEST 1] -- ◉"<<std::endl
	<<BB<<TEST1<<W<<std::endl<<std::endl;
	{
		Bureaucrat buro("pepe", 27);
		std::cout<<buro.getName()<<"'s grade: "
		<<buro.getGrade()<<std::endl;
	}
	
	std::cout<<std::endl
	<<"___________________________________"<<std::endl
	<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST 2] -- ◉"<<std::endl
	<<BB<<TEST2<<W<<std::endl<<std::endl;
	{
		Bureaucrat *buro;
		
		try{
			buro = new Bureaucrat("pepe", 180);		
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
	}

	std::cout<<std::endl
	<<"___________________________________"<<std::endl
	<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST 3] -- ◉"<<std::endl
	<<BB<<TEST3<<W<<std::endl<<std::endl;
	{
		Bureaucrat *buro = new Bureaucrat("pepe", 150);		
		
		try{
			buro->incrementGrade();
			std::cout<<G<<"incrementation Success."<<W<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
		try{
			buro->decrementGrade();
			std::cout<<G<<"decrementation Success."<<W<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
		try{
			buro->decrementGrade();
			std::cout<<G<<"decrementation Success."<<W<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
		delete buro; 
	}
	return 0;
}
