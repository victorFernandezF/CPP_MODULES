/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/11/06 18:14:18 by victofer         ###   ########.fr       */
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

int main(int argc, char **argv)
{
 	std::string argument;
	std::vector<int>vec;
	if (argc < 3){
		if (argc == 2)
			std::cout<<BR<<" Only one number?\n"<<W<<std::endl;
		else
			std::cout<<BR<<" What am I supose to sort?\n"<<W<<std::endl;
		return (1);
	}
	atexit(leaks);
	PmergeMe pm;
	try{
		pm.sortVector(argc, argv);
		pm.sortDeque(argc, argv);	
	}catch(std::exception &e)
	{
		std::cout<<BR<<" "<<e.what()<<W<<std::endl;
	}
	return 0;
}

