/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:54:05 by victofer          #+#    #+#             */
/*   Updated: 2023/08/07 13:42:51 by victofer         ###   ########.fr       */
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
		
		std::cout<<BW<<"   ---- [TEST 1] ---- "<<W<<std::endl;
		printP(a, b, c, point);	
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<BW<<"Point is "<<BU<<"inside"<<BW<<" triangle"<<std::endl;
		else
			std::cout<<BW<<"Point is "<<BU<<"outside"<<BW<<" triangle"<<std::endl;
		std::cout<<"___________________________"<<std::endl<<std::endl;
	}
	{
		Point a(0, 0);
		Point b(10, 30);
		Point c(20, 0);
		Point point(30, 15);
		bool res;

		std::cout<<BW<<"   ---- [TEST 2] ---- "<<W<<std::endl;
		printP(a, b, c, point);	
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<BW<<"Point is "<<BU<<"inside"<<BW<<" triangle"<<std::endl;
		else
			std::cout<<BW<<"Point is "<<BU<<"outside"<<BW<<" triangle"<<std::endl;
		std::cout<<"___________________________"<<std::endl<<std::endl;
	}
	{
		Point a(-9, 20);
		Point b(42, 24);
		Point c(10, 1);
		Point point(0, 21); //on edge
		bool res;

		std::cout<<BW<<"   ---- [TEST 3] ---- "<<GR<<" (on edge)"<<std::endl;
		printP(a, b, c, point);	
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<BW<<"Point is "<<BU<<"inside"<<BW<<" triangle"<<std::endl;
		else
			std::cout<<BW<<"Point is "<<BU<<"outside"<<BW<<" triangle"<<std::endl;
		std::cout<<"___________________________"<<std::endl<<std::endl;
	}
	{
		Point a(-9, 20);
		Point b(42, 24);
		Point c(10, 1);
		Point point(-9, 20); //on the vertice
		bool res;

		std::cout<<BW<<"   ---- [TEST 4] ---- "<<GR<<" (on vertice)"<<std::endl;
		printP(a, b, c, point);	
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<BW<<"Point is "<<BU<<"inside"<<BW<<" triangle"<<std::endl;
		else
			std::cout<<BW<<"Point is "<<BU<<"outside"<<BW<<" triangle"<<std::endl;
		std::cout<<"___________________________"<<std::endl<<std::endl;
	}
	return 0;
}
