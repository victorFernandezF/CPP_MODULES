/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/13 11:13:31 by victofer         ###   ########.fr       */
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

void toUpperChar(char &c){
	c = std::toupper(c);
}

void strToLower(std::string &str){
	int i = -1;
	while (str[++i])
		str[i] = std::tolower(str[i]);
}

int main(void)
{
	atexit(leaks);
	int max = 4;
	printTestHeaders(1, TEST1, 0);
	{
		int nb[4];	
		for(int i = 0; i < max; i++)
			nb[i] = i + 20;

		::printArray(nb, max, "before iter");
		::iter(nb, max, &substraction);
		std::cout<<std::endl;
		::printArray(nb, max, "after iter");
		std::cout<<std::endl;
	}
	printTestHeaders(2, TEST2, 1);
	{
		char c[4];
		
		c[0] = 'a';
		c[1] = 'b';
		c[2] = 'c';
		c[3] = 'd';
		
		::printArray(c, max, "before iter");
		::iter(c, max, &toUpperChar);
		std::cout<<std::endl;
		::printArray(c, max, "after iter");
	}
	printTestHeaders(3, TEST3, 1);
	{
		std::string str[4];
		
		str[0] = "HELLO";
		str[1] = "WORLD";
		str[2] = "TEST";
		str[3] = "TEST_2";
		
		::printArray(str, max, "before iter");
		::iter(str, max, &strToLower);
		std::cout<<std::endl;
		::printArray(str, max, "after iter");
	}
	printTestHeaders(4, TEST4, 1);
	{
		float flo[4];
		
		flo[0] = 42.5f;
		flo[1] = 0.25f;
		flo[2] = 1.01f;
		flo[3] = 27.1f;
		
		::printArray(flo, max, "before iter");
		::iter(flo, max, &addition);
		std::cout<<std::endl;
		::printArray(flo, max, "after iter");
	}
	return (0);
}
