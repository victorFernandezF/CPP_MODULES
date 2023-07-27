/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:46:46 by victofer          #+#    #+#             */
/*   Updated: 2023/07/27 12:37:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixedValue(0){
	std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const Fixed& obj){
	std::cout<<"Copy constructor called"<<std::endl;
	this->_fixedValue = obj.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &obj){
	std::cout<<"Copy assignmen operatorcalled"<<std::endl;
	if (this != &obj)
		this->_fixedValue = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed(void){
	std::cout<<"Destructor called"<<std::endl;
}
int Fixed::getRawBits(void) const{
	std::cout<<"getRawBits function member called"<<std::endl;
	return (this->_fixedValue);
}
void Fixed::setRawBits(int const raw){
	this->_fixedValue = raw;
}