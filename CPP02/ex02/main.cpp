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
		Fixed a(5);
		Fixed b(2);
		std::cout<<std::endl<<BR<<"--- [MY TESTS] --- "<<W<<std::endl;
		std::cout<<std::endl<<G<<" ** [ARITHMETIC OPERATORS] ** "<<W<<std::endl;
		std::cout <<BOLD<<"	Initial value of a:      "<<a <<std::endl;
		std::cout <<BOLD<<"	Initial value of b:      "<<b<<Y<<std::endl;
		std::cout <<Y<<"	Testing '+' -> {a + b}:  "<<W<<a + b<<std::endl;
		std::cout <<BY<<"	Testing '-' -> {a - b}:  "<<W<<a - b<<std::endl;
		std::cout <<Y<<"	Testing '*' -> {a * b}:  "<<W<<a * b<<std::endl;
		std::cout <<BY<<"	Testing '/' -> {a / b}:  "<<W<<a / b<<std::endl;
		std::cout <<Y<<std::endl;
	}
	{
		Fixed a(5);
		Fixed b(5);
		std::cout<<G<<" ** [INCREMETN DECREMENT] ** "<<W<<std::endl;
		std::cout<<BB<<"     [INCREMENT]"<<std::endl;
		std::cout <<BOLD<<"	Initial value of a:  "<<a<<std::endl;
		std::cout <<BOLD<<"	Initial value of b:  "<<b<<std::endl;
		std::cout <<Y<<"	Result of doing a++: "<<W<<a++<<std::endl;
		std::cout <<BY<<"	Result of doing ++b: "<<W<<++b<<std::endl;
		std::cout <<B<<"	  Current values "<<std::endl;
		std::cout <<Y<<"	Current value of a:  "<<W<<a<<std::endl;
		std::cout <<BY<<"	Current value of b:  "<<W<<b<<std::endl;
	}
	{
		Fixed a(5);
		Fixed b(5);
		std::cout<<std::endl<<BB<<"     [DECREMENT]"<<std::endl;
		std::cout <<BOLD<<"	Initial value of a:  "<<a<<std::endl;
		std::cout <<BOLD<<"	Initial value of b:  "<<b<<std::endl;
		std::cout <<Y<<"	Result of doing a--: "<<W<<a--<<std::endl;
		std::cout <<BY<<"	Result of doing --b: "<<W<<--b<<std::endl;
		std::cout <<B<<"	  Current values "<<std::endl;
		std::cout <<Y<<"	Current value of a:  "<<W<<a<<std::endl;
		std::cout <<BY<<"	Current value of b:  "<<W<<b<<std::endl;
	}
	{
		Fixed a(27);
		Fixed b(42);
		std::cout<<std::endl<<G<<" ** [MAX MIN FUNCTIONS] ** "<<W<<std::endl;
		std::cout <<BOLD<<"	Initial value of a: "<<a<<std::endl;
		std::cout <<BOLD<<"	Initial value of b: "<<b<<std::endl;
		std::cout <<Y<<"	Result of doing max(a, b): "<<W<<Fixed::max(a, b)<<std::endl;
		std::cout <<BY<<"	Result of doing min(a, b): "<<W<<Fixed::min(a, b)<<std::endl;
	}
	{
		Fixed a(405);
		Fixed b(30);
		std::cout<<std::endl<<G<<" ** [COMPARISION OPERATORS] ** "<<W<<std::endl;
		std::cout<<BOLD<<"	Initial value of a: "<<a<<std::endl;
		std::cout <<BOLD<<"	Initial value of b: "<<b<<std::endl;
		std::cout <<Y<<"	Comparing {a > b}:  "<<W<<(a > b)<<std::endl;
		std::cout <<BY<<"	Comparing {a >= b}: "<<W<<(a >= b)<<std::endl;
		std::cout <<Y<<"	Comparing {a < b}:  "<<W<<(a < b)<<std::endl;
		std::cout <<BY<<"	Comparing {a <= b}: "<<W<<(a <= b)<<std::endl;
		std::cout <<Y<<"	Comparing {a == b}: "<<W<<(a == b)<<std::endl;
		std::cout <<BY<<"	Comparing {a != b}: "<<W<<(a != b)<<std::endl;
		std::cout<<std::endl<<BR<<"--- [DONE] --- "<<W<<std::endl;
	}
	return 0;
}
