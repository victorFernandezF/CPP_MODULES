/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/10/25 10:27:34 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"
#include "EasyFind.hpp"
#include <iostream>
#include <vector>
#include <array>

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
		std::vector<int> vec(5);
		vec[0] = 25;
		vec[1] = 42;
		vec[2] = 0;
		vec[3] = 27;
		vec[4] = 156;
		try{
			::easyFind(vec, 42);
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
	}
	printTestHeaders(2, TEST2, 1);
	{
		std::array<int, 5> arr;
		arr[0] = 200;
		arr[1] = 800;
		arr[2] = 14;
		arr[3] = 98;
		arr[4] = 1259;
		try{
			::easyFind(arr, 98);
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
	}
	printTestHeaders(3, TEST3, 1);
	{
		std::array<int, 5> arr;
		arr[0] = 200;
		arr[1] = 800;
		arr[2] = 14;
		arr[3] = 98;
		arr[4] = 1259;
		try{
			::easyFind(arr, 25);
		}catch (std::exception &e){
			std::cout<<BR<<e.what()<<W<<std::endl;
		}
	}
	return 0;
}
