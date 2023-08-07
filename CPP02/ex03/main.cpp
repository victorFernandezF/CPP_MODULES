/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:54:05 by victofer          #+#    #+#             */
/*   Updated: 2023/08/07 12:46:44 by victofer         ###   ########.fr       */
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
		Point point(20, 0);
		bool res;
		
		printP(a, b, c, point);	
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<"Point is inside triangle"<<std::endl;
		else
			std::cout<<"Point is outside triangle"<<std::endl;
	}
	/* {
		Point a(0, 0);
		Point b(10, 30);
		Point c(20, 0);
		Point point(30, 15);
		bool res;
			
		res = bsp(a, b, c, point);
		if (res)
			std::cout<<"Point is inside triangle"<<std::endl;
		else
			std::cout<<"Point is outside triangle"<<std::endl;
	} */
	return 0;
}
