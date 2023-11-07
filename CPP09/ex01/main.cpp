/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/11/07 18:26:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colours.h"
#include "RPN.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q RPN");
}

int main(int argc, char **argv)
{
 	std::string argument;
	std::stack<int>st;
	
	atexit(leaks);
	if (argc != 2)
	{
		std::cout<<BR<<"Error: incorrect number of arguments"<<W<<std::endl;
		return -1;
	}
	try{
		Rpn rpn;
		argument = argv[1];
		rpn.rpn(argument);
	}catch (std::exception &e)
	{
		std::cout<<BR<<"ERROR: "<<e.what()<<W<<std::endl;
	}
	return 0;
}
