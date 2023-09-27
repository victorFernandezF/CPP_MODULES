/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/04 18:39:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"
#include "ScalarConverter.hpp"
#include <iostream>
#include <stdlib.h>

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
}

int main(int argc, char **argv)
{
	std::string arg;
	
	atexit(leaks);
	if (argc != 2){
		std::cout<<BR<<"Error: Incorrect number of arguments"<<W<<std::endl;
		return 0;
	}
	arg = argv[1];
	ScalarConverter::convert(arg);
	return 0;
}
