/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:46:46 by victofer          #+#    #+#             */
/*   Updated: 2023/07/27 13:39:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractBits = 0; 

//D efault Constructor
Fixed::Fixed(void): _fixedValue(0){
	std::cout<<"Default constructor called"<<std::endl;
}

// Copy contructor
Fixed::Fixed(const Fixed& obj){
	std::cout<<"Copy constructor called"<<std::endl;
	this->_fixedValue = obj.getRawBits();
}

// Operator Overload
Fixed &Fixed::operator=(const Fixed &obj){
	std::cout<<"Copy assignmen operatorcalled"<<std::endl;
	if (this != &obj)
		this->_fixedValue = obj.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed(void){
	std::cout<<"Destructor called"<<std::endl;
}

// Function member getRawBits
int Fixed::getRawBits(void) const{
	std::cout<<"getRawBits function member called"<<std::endl;
	return (this->_fixedValue);
}

// Function member setRaeBits
void Fixed::setRawBits(int const raw){
	this->_fixedValue = raw;
}