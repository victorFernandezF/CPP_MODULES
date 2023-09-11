/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/11 11:14:15 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"
#include "Iter.hpp"
#include <iostream>
#include <stdlib.h>

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
		int nb[4];
		int max = 4;
		
		for(int i = 0; i < max; i++)
			nb[i] = i + 1;

		::printArray(nb, max, "before iter");
		::iter(nb, max, &swap);
		std::cout<<std::endl;
		::printArray(nb, max, "after iter");
		std::cout<<std::endl;
	}
	printTestHeaders(2, TEST2, 1);
	{
		char c[3];
		int max = 3;
		
		c[0] = 'a';
		c[1] = 'b';
		c[2] = 'c';
		
		::printArray(c, max, "before iter");
		::iter(c, max, &swap);
		std::cout<<std::endl;
		::printArray(c, max, "after iter");
	}
	printTestHeaders(3, TEST3, 1);
	{
		std::string str[3];
		int max = 3;
		
		str[0] = "HELLO";
		str[1] = "WORLD";
		str[2] = "TEST";
		
		::printArray(str, max, "before iter");
		::iter(str, max, &swap);
		std::cout<<std::endl;
		::printArray(str, max, "after iter");
	}
		printTestHeaders(4, TEST4, 1);
	{
		float flo[3];
		int max = 3;
		
		flo[0] = 42.5f;
		flo[1] = 0.25f;
		flo[2] = 105.347f;
		
		::printArray(flo, max, "before iter");
		::iter(flo, max, &swap);
		std::cout<<std::endl;
		::printArray(flo, max, "after iter");
	}
}
