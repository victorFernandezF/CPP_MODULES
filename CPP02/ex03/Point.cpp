/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:12:49 by victofer          #+#    #+#             */
/*   Updated: 2023/08/07 11:12:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// CONTRUCTORS PACK
Point::Point(): _x(0), _y(0){}
Point::Point(float const cx, float const cy):_x(cx), _y(cy){}
Point::Point(Point &copy): _x(copy.getX()), _y(copy.getY()){}
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

Fixed area(Point const a, Point const b, Point const c){
	Fixed area, ax, ay, bx, by, cx, cy;

	ax = a.getX().toFloat();
	ay = a.getY().toFloat();
	bx = b.getX().toFloat();
	by = b.getY().toFloat();
	cx = c.getX().toFloat();
	cy = c.getY().toFloat();
	area = ax * (by - cy) + bx * (cy - ay) + cx * (ay - by);
	area = area / 2;
	if (area < 0)
		area = area * -1;
	std::cout<<"area is: "<<area<<std::endl;
	return (area);
	//Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By)
}

/* bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	
} */