/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/14 19:04:52 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"
#include "Span.hpp"
#include <iostream>

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex01");
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
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	printTestHeaders(2, TEST2, 1);
	{
		Span sp = Span(3);
		sp.addNumber(5);
		sp.addNumber(25);
		sp.addNumber(54);
		sp.print();
		try{
			sp.addNumber(546);
			sp.addNumber(5436);
		}catch(std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
	}
	printTestHeaders(3, TEST3, 1);
	{
		Span sp = Span(5);
		sp.addNumber(1);
 		sp.addNumber(50);
		sp.addNumber(28); 
		sp.addNumber(15); 
		sp.addNumber(29); 
		sp.print();
		std::cout<<"\n";
		try{
			std::cout<< "shortestSpan: "<<sp.shortestSpan()<<std::endl;
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
		try{
			std::cout<< "longestSpan: "<<sp.longestSpan()<<std::endl;
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
		
		std::cout<<C<<"\n * We can try to create a span of 1 element and call\n"
		<<"  shortest and longest span function. That should throw an exception *"
		<<W<<std::endl;
		
		Span sp2 = Span(1);
		sp2.addNumber(27);
		std::cout<<"\n";
		try{
			std::cout<< "shortestSpan: "<<sp2.shortestSpan()<<std::endl;
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
		try{
			std::cout<< "longestSpan: "<<sp2.longestSpan()<<std::endl;
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
	}
	printTestHeaders(4, TEST4, 1);
	{
		unsigned int N = 20000;
		Span sp =Span(N);
		sp.addManyNumbers(N);
		//span.print();  //That's going to print a lot of numbers... 
		std::cout<<"\nshortestSpan: "<<C<<sp.shortestSpan()<<W<<"\n";
		std::cout<<"longestSpan: "<<C<<sp.longestSpan()<<W<<"\n";
		
	}
	return 0;
}
