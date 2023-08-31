/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/31 12:55:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colours.h"
#include <limits>
#include <stdlib.h>

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
}

int	isDigit(std::string str){
	size_t flag = 0;
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] >= '0' && str[i] <= '9')
			flag++;
	if (flag == str.length())
		return 1;
	return (0);		
}

int isFloat(std::string str)
{
	double res = 0;
	if (str[str.length() - 1] == 'f')
	{
		res = atof(str.c_str());
		
		return 1;
	}
	return 0;
}

int	isInt(std::string str){
	long int res;

	if (str[str.length() - 1] == 'f')
		return (0);
	res = atol(str.c_str());
	if (res >= INT_MIN && res <= INT_MAX)
		return 1;
	return 0;
}

int	isChar(std::string str){
	if (str.length() == 1)
		if ((str[0] >= 26 && str[0] <= 126) && (!isDigit(str)))
			return 1;
	return (0);		
}

int detectType(std::string str){
	if (isChar(str))
		return CHAR;
	if (isInt(str))
		return INT;
	if (isFloat(str))
		return FLOAT;
	return (0);
}

int main(int argc, char **argv)
{
	atexit(leaks);
	if (argc == 2){
		std::cout<<detectType(argv[1])<<std::endl;
		return 0;
	}
	std::cout<<BR<<"Error: Incorrect number of arguments"<<W<<std::endl;

	return 0;
}
