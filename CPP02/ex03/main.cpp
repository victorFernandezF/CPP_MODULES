/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:54:05 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 12:10:34 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	{
		Point a(0, 0);
		Point b(10, 30);
		Point c(20, 0);
		Point point(10, 0);
		bool res;
		
		std::cout<<BOLD<<"------ [TEST 1] ------ "<<W<<std::endl;
		printP(a, b, c, point);	
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<BOLD<<"Point is "<<BU<<"inside"<<BOLD<<" triangle"<<std::endl;
		else
			std::cout<<BOLD<<"Point is "<<BU<<"outside"<<BOLD<<" triangle"<<std::endl;
		std::cout<<"___________________________"<<std::endl<<std::endl;
	}
 	{
		Point a(0, 0);
		Point b(10, 30);
		Point c(20, 0);
		Point point(30, 15);
		bool res;

		std::cout<<BOLD<<"------- [TEST 2] ------ "<<W<<std::endl;
		printP(a, b, c, point);	
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<BOLD<<"Point is "<<BU<<"inside"<<BOLD<<" triangle"<<std::endl;
		else
			std::cout<<BOLD<<"Point is "<<BU<<"outside"<<BOLD<<" triangle"<<std::endl;
		std::cout<<"___________________________"<<std::endl<<std::endl;
	}
	{
		Point a(-9, 20);
		Point b(42, 24);
		Point c(10, 1);
		Point point(0, 21); //on edge
		bool res;

		std::cout<<BOLD<<"------ [TEST 3] ------ "<<GR<<" (on edge)"<<std::endl;
		printP(a, b, c, point);	
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<BOLD<<"Point is "<<BU<<"inside"<<BOLD<<" triangle"<<std::endl;
		else
			std::cout<<BOLD<<"Point is "<<BU<<"outside"<<BOLD<<" triangle"<<std::endl;
		std::cout<<"___________________________"<<std::endl<<std::endl;
	}
	{
		Point a(-9, 20);
		Point b(42, 24);
		Point c(10, 1);
		Point point(-9, 20); //on the vertice
		bool res;

		std::cout<<BOLD<<"------ [TEST 4] ------ "<<GR<<" (on vertice)"<<std::endl;
		printP(a, b, c, point);	
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<BOLD<<"Point is "<<BU<<"inside"<<BOLD<<" triangle"<<std::endl;
		else
			std::cout<<BOLD<<"Point is "<<BU<<"outside"<<BOLD<<" triangle"<<std::endl;
		std::cout<<"___________________________"<<std::endl<<std::endl;
	}
	return 0;
}
