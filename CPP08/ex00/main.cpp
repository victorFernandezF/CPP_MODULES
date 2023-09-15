/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/15 10:45:41 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"
#include "EasyFind.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <list>

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
}

void printTestHeaders(int nbTest, std::string testHeader, int newLine){
	if (newLine == 1)
		std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST "<<nbTest<<"] -- ◉"<<std::endl
	<<BB<<testHeader<<W<<std::endl;
}

int main(void)
{
	atexit(leaks);
	printTestHeaders(1, TEST1, 0);
	{
		std::vector<int> vect(5);
		for (size_t i= 0; i < vect.size(); i++)
			vect[i] = i + 1;
		try{
			::easyFind(vect, 5);
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
	}
	printTestHeaders(2, TEST2, 1);
	{
		std::array<int, 5> arr;
		for (size_t i= 0; i < arr.size(); i++)
			arr[i] = i + 1;
		try{
			::easyFind(arr, 4);
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
	}
	printTestHeaders(3, TEST3, 1);
	{
		std::array<int, 5> arr;
		for (size_t i= 0; i < arr.size(); i++)
			arr[i] = i + 1;
		try{
			::easyFind(arr, 25);
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
	}
	return 0;
}
