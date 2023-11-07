/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/11/07 10:50:44 by victofer         ###   ########.fr       */
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
	atexit(leaks);
	try{
		PmergeMe pm;
		pm.sortVector(argc, argv);
		pm.sortDeque(argc, argv);	
	}catch(std::exception &e)
	{
		std::cout<<BR<<" ERROR: "<<e.what()<<W<<std::endl;
	}
	return 0;
}

