/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:38:37 by victofer          #+#    #+#             */
/*   Updated: 2023/08/09 12:41:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed{
	private:
		int _fixedValue;
		static const int _fractBits; 
	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		Fixed & operator=(const Fixed &obj);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif