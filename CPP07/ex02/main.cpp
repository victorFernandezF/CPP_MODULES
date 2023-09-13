/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/13 11:04:01 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"
#include "Array.hpp"
#include <iostream>
#include <stdlib.h>
#define MAX_VAL 170
void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex02");
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
	{
		printTestHeaders(1, TEST1, 0);
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	printTestHeaders(2, TEST2, 1);
	{
		Array<int>  nb(3);
		Array<int>  nb2;
		nb[0] = 21;
		nb[1] = 22;
		nb[2] = 23;
		
		std::cout<<C<<" * Printing first array (nb)\n"<<W;
		nb.print("nb");
		nb2 = nb;
		std::cout<<C<<"\n * Printing second array (nb2)\n"<<W; 
		nb2.print("nb2");
		
		std::cout<<C<<"\n * Modifying second array (nb2)\n"<<W; 
		nb2[0] = 41;
		nb2[1] = 42;
		nb2[2] = 43;
 
		std::cout<<C<<"\n * Printing first array (nb)\n"<<W; 
		nb.print("nb");
		std::cout<<"\n"; 
		std::cout<<C<<"\n * Printing second array (nb2)\n"<<W; 
		nb2.print("nb2");
		std::cout<<C<<"\n * Modification should only affect the second array *\n"<<W; 
	}
	printTestHeaders(3, TEST3, 1);
	{
		Array <char> letters(3);
		letters[0] = 'a';
		letters[1] = 'b';
		letters[2] = 'c';
		
		std::cout<<C<<"\n * Create array of 3 chars letters{a, b, c})" 
		<<"\n * Try to access its values\n"<<W; 
		try{
			std::cout<<"letters[0] -> "<<letters[0]<<std::endl;
		}catch(std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
		try{
			std::cout<<"letters[1] -> "<<letters[1]<<std::endl;
		}catch(std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
		try{
			std::cout<<"letters[2] -> "<<letters[2]<<std::endl;
		}catch(std::exception &e){
			std::cout<<e.what()<<std::endl;
		}

		std::cout<<C<<"\n * Array size is 3 so trying to acces to\n"
		<<"   letters[3] will throw an excepion\n"<<W; 
		
		try{
			std::cout<<"letters[3] -> "<<letters[3]<<std::endl;
		}catch(std::exception &e){
			std::cout<<e.what()<<std::endl;
		}

		std::cout<<C<<"\n * Trying to acces with an index less than zero\n"
		<<"   will throw an excepion\n"<<W; 

		try{
			std::cout<<"letters[-20] -> "<<letters[-20]<<std::endl;
		}catch(std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
	}

	printTestHeaders(4, TEST4, 1);
	{
		std::cout<<C<<" * Create array of 100 ints\n"<<W; 
		Array <int> nb(100);
		for (size_t i = 0; i < 100; i++)
			nb[i] = 200 + i;
		std::cout<<"Testing size function: "<<nb.size()<<std::endl;
	}
	return 0;
}
