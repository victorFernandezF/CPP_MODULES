/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:54:05 by victofer          #+#    #+#             */
/*   Updated: 2023/07/27 12:05:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	{
		std::cout<<std::endl<<BR<<"--- [SUBJECT TEST] --- "<<W<<std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl; //0
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout<<std::endl<<BR<<"--- [MY TESTS] --- "<<W<<std::endl;
		std::cout<<std::endl<<G<<" - [OPERATIONS] - "<<W<<std::endl;
		Fixed f(5);
		Fixed g(2);
		std::cout <<Y<<"	Initial value of f:      "<<W<<f <<std::endl;
		std::cout <<Y<<"	Testing '+' -> {f + 2}:  "<<W<<f + 2<<std::endl;
		std::cout <<Y<<"	Testing '-' -> {f - 1}:  "<<W<<f - 1<<std::endl;
		std::cout <<Y<<"	Testing '*' -> {f * 2}:  "<<W<<f * 2<<std::endl;
		std::cout <<Y<<"	Testing '/' -> {f / 2}:  "<<W<<f / 2<<std::endl;
		std::cout <<Y<<std::endl;
	}
	{
		std::cout<<G<<" - [INCREMETN DECREMENT] - "<<W<<std::endl;
		Fixed c(5);
		Fixed d(5);
		std::cout<<BB<<"     [INCREMENT]"<<std::endl;
		std::cout <<Y<<"	Initial value of c:  "<<G<<c<<std::endl;
		std::cout <<Y<<"	Initial value of d:  "<<G<<d<<std::endl;
		std::cout <<Y<<"	Result of doing c++: "<<G<<c++<<std::endl;
		std::cout <<Y<<"	Result of doing ++d: "<<G<<++d<<std::endl;
		std::cout <<B<<"	  Current values "<<std::endl;
		std::cout <<Y<<"	Current value of c:  "<<G<<c<<std::endl;
		std::cout <<Y<<"	Current value of d:  "<<G<<d<<std::endl;
		std::cout<<std::endl<<BB<<"     [DECREMENT]"<<std::endl;
		std::cout <<Y<<"	Initial value of c:  "<<G<<c<<std::endl;
		std::cout <<Y<<"	Initial value of d:  "<<G<<d<<std::endl;
		std::cout <<Y<<"	Result of doing c--: "<<G<<c--<<std::endl;
		std::cout <<Y<<"	Result of doing --d: "<<G<<--d<<std::endl;
		std::cout <<B<<"	  Current values "<<std::endl;
		std::cout <<Y<<"	Current value of c:  "<<G<<c<<std::endl;
		std::cout <<Y<<"	Current value of d:  "<<G<<d<<std::endl;
	}
	return 0;
}
