/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/11/03 12:55:48 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colours.h"
#include "PmergeMe.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q PmergeMe");
}

std::string delSpaces(std::string str){
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
	return str;
}

int main(int argc, char **argv)
{
 	std::string argument;
	std::vector<int>vec;
	if (argc < 3){
		std::cout<<BR<<"What am I supose to sort?\n"<<W<<std::endl;
		return (1);
	}
	//atexit(leaks);
	PmergeMe pm;
	pm.sortVector(argc, argv);
	return 0;
}

