/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:12:49 by victofer          #+#    #+#             */
/*   Updated: 2023/08/07 12:51:48 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// CONTRUCTORS PACK
Point::Point(): _x(0), _y(0){}
Point::Point(float const cx, float const cy):_x(cx), _y(cy){}
Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY()){}
Point &Point::operator=(const Point &obj){
	(void)obj;
	return (*this);
}
Point::~Point(){}

// GETTERS AND SETTERS
Fixed Point::getX() const{
	return (this->_x);
}
Fixed Point::getY() const{
	return (this->_y);
}

void Point::printPoint() const{
	std::cout<<"("<<this->getX()<<","<<this->getY()<<")";
}
