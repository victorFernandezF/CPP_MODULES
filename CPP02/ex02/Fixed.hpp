/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:38:37 by victofer          #+#    #+#             */
/*   Updated: 2023/07/27 13:37:28 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
#include <fstream>
#include <cmath>

class Fixed{
	private:
		int _fixedValue;
		static const int _fractBits; 
	public:
		Fixed(void); // Default contructor
		Fixed(const Fixed &obj); // Copy contructor
		Fixed(const int nb); // Int contructor
		Fixed(const float nb); // Float contructor
		~Fixed(void); // Destructor
		Fixed & operator=(const Fixed &obj); // asignaent operator
		
		// OVERLOAD OPERATOR 
		bool operator<(Fixed fix) const;
		bool operator>(Fixed fix) const;
		bool operator<=(Fixed fix) const;
		bool operator>=(Fixed fix) const;
		bool operator!=(Fixed fix) const;
		bool operator==(Fixed fix) const;
		float operator+(Fixed fix) const;
		float operator-(Fixed fix) const;
		float operator*(Fixed fix) const;
		float operator/(Fixed fix) const;
		Fixed & operator++(void);
		Fixed & operator--(void);
		Fixed operator++(int val);
		Fixed operator--(int val);

		//MAX MIN STUFF
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);
		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		
		// GETTERS AND SETTERS
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream    &operator<<(std::ostream &obj, Fixed const &fixed);
#endif