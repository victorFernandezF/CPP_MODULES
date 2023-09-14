/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/14 10:43:59 by victofer         ###   ########.fr       */
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
		Span span(3);
		try{
			span.addNumber(5);
			span.addNumber(25);
			span.addNumber(54);
			span.addNumber(546);
			span.print();
		}catch(std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
	}
	printTestHeaders(2, TEST2, 1);
	{
		Span span(5);
		span.addNumber(1);
 		span.addNumber(50);
		span.addNumber(28); 
		span.addNumber(15); 
		span.addNumber(81); 
		span.print();
		std::cout<<"\n";
		try{
			std::cout<< "shortestSpan: "<<span.shortestSpan()<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
		try{
			std::cout<< "longestSpan: "<<span.longestSpan()<<std::endl;
		}catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
	}
	printTestHeaders(3, TEST3, 1);
	{
		Span span(100);
		span.addManyNumbers(100);
		span.print();
	}
	return 0;
}
