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

int const Fixed::_fractBits = 8; 

//D efault Constructor
Fixed::Fixed(void): _fixedValue(0){
	//std::cout<<"Default constructor called"<<std::endl;
}

// Copy contructor
Fixed::Fixed(const Fixed& obj){
	//std::cout<<"Copy constructor called"<<std::endl;
	this->_fixedValue = obj.getRawBits();
}

Fixed::Fixed(const int nb){
	//std::cout<<"Int constructor called"<<std::endl;
	this->_fixedValue = nb << this->_fractBits;
}

Fixed::Fixed(const float nb){
	//std::cout<<"Float constructor called"<<std::endl;
	this->_fixedValue = roundf(nb * (1 << this->_fractBits));
}

// Operator Overload
Fixed &Fixed::operator=(const Fixed &obj){
	//std::cout<<"Copy assignmen operatorcalled"<<std::endl;
	if (this != &obj)
		this->_fixedValue = obj.getRawBits();
	return (*this);
}

// Operator Overload +
float Fixed::operator+(Fixed fix)const{
	return (this->toFloat() + fix.toFloat());
}

float Fixed::operator-(Fixed fix)const{
	return (this->toFloat() - fix.toFloat());
}

float Fixed::operator*(Fixed fix)const{
	return (this->toFloat() * fix.toFloat());
}

float Fixed::operator/(Fixed fix)const{
	return (this->toFloat() / fix.toFloat());
}

bool Fixed::operator<(Fixed fix) const{
	return (this->toFloat() < fix.toFloat());
}

bool Fixed::operator>(Fixed fix) const{
	return (this->toFloat() > fix.toFloat());
}

bool Fixed::operator<=(Fixed fix) const{
	return (this->toFloat() <= fix.toFloat());
}

bool Fixed::operator>=(Fixed fix) const{
	return (this->toFloat() >= fix.toFloat());
}

bool Fixed::operator!=(Fixed fix) const{
	return (this->toFloat() != fix.toFloat());
}

bool Fixed::operator==(Fixed fix) const{
	return (this->toFloat() == fix.toFloat());
}

Fixed &Fixed::operator++(void){
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed &Fixed::operator--(void){
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int val){
	Fixed aux = *this;
	if (!val)
		val = 1;
	this->setRawBits(this->getRawBits() + val);
	return (aux);
}

Fixed Fixed::operator--(int val){
	Fixed aux = *this;
	if (!val)
		val = 1;
	this->setRawBits(this->getRawBits() - val);
	return (aux);
}

// MAX MIN

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2){
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);

}
const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2){
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2){
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2){
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

// Destructor
Fixed::~Fixed(void){
	//std::cout<<"Destructor called"<<std::endl;
}

// Function member getRawBits
int Fixed::getRawBits(void) const{
	//std::cout<<"getRawBits function member called"<<std::endl;
	return (this->_fixedValue);
}

// Function member setRaeBits
void Fixed::setRawBits(int const raw){
	this->_fixedValue = raw;
}

float Fixed::toFloat(void) const{
	return ((float)this->_fixedValue / (float)(1 << this->_fractBits));
}

int Fixed::toInt(void) const{
	return (this->_fixedValue >> this->_fractBits);
};

std::ostream &operator<<(std::ostream &obj, Fixed const &fixed)
{
	obj << fixed.toFloat();
	return (obj);
}