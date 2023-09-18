/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/18 18:25:11 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "colours.h"
#include "MutantStack.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex02");
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
		MutantStack<int> stack;
		
		
		
	}
	return 0;
}