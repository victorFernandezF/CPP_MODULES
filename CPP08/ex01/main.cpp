/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/13 19:14:56 by victofer         ###   ########.fr       */
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
		Span span(3);
		span.addNumber(85);
		span.addNumber(35);
		span.addNumber(14);
		std::cout<< "shortestSpan: "<<span.shortestSpan()<<std::endl;
		span.print();
	}
	//printTestHeaders(3, TEST3, 1);
	{
		
	}
	return 0;
}
