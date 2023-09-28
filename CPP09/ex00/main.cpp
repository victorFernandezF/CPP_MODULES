/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/28 18:06:36 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <fstream>
#include "colours.h"
#include "BitcoinExchange.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q btc");
}

int main(int argc, char **argv)
{
 	std::string filename;
	filename = argv[1];
	
	atexit(leaks);
	if (argc != 2)
		return 0;
	try{
		BitcoinExchange exchange;
		exchange.exchange(filename);
	}catch (std::exception &e){
		std::cout<<BR<<e.what()<<W<<"\n";
	}
}
