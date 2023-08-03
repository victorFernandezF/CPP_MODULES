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
		std::cout<<std::endl<<G<<"	[SUBJECT TEST]"<<W<<std::endl;
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
		std::cout<<std::endl<<G<<"	[MORE TEST]"<<W<<std::endl;
		Fixed c(3);
		Fixed d(3);
		Fixed const e(Fixed(6) - Fixed(2));
		std::cout <<Y<<"Initial value of c:  "<<G << c << std::endl;
		std::cout <<BY<<"Result of doing c++: " <<BG<< c++ << std::endl;
		std::cout <<Y<<"Result of doing c--: " <<G<< c-- << std::endl;
		std::cout <<BY<<"Current value of c:  " <<BG<< c << std::endl;
		std::cout <<Y<<"Initial value of d:  "<<G<< d << std::endl;
		std::cout <<BY<<"Result of doing ++d: "<<BG<< ++d << std::endl;
		std::cout <<Y<<"Result of c + 2 - 3: "<<G<< c + 2 - 1 << std::endl;
		std::cout <<BY<<"Initial value of e:  " <<BG<< e << std::endl;
		std::cout <<Y<<"Min between c and d: "<<G<< Fixed::min( c, e) << std::endl;
		std::cout <<BY<<"Max between c and d: "<<BG<< Fixed::min( c, e) <<W<< std::endl;
	}
	return 0;
}
