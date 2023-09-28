/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/28 19:23:15 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colours.h"
//#include "RPN.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q RPN");
}

std::string delSpaces(std::string str){
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
	return str;
}

int main(int argc, char **argv)
{
 	std::string argument;
 	std::string noSpaces;
	
	atexit(leaks);
	if (argc != 2)
		return 0;
	argument = argv[1];
	noSpaces = delSpaces(argument);
	//RPN rpn;
	//RPN.rpn(noSpaces);
}
