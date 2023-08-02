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

class Fixed{
	private:
		int _fixedValue;
		static const int _fractBits; 
	public:
		Fixed(void); //Default contructor
		Fixed(const Fixed &obj); //Copy contructor
		Fixed(const int nb); //Int contructor
		Fixed(const float nb); //Float contructor
		Fixed & operator=(const Fixed &obj);
		Fixed & operator<<(const Fixed &obj); 
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream    &operator<<(std::ostream &obj, Fixed const &fixed);
#endif