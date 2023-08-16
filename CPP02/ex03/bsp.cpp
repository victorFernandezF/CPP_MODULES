/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:09:41 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 12:11:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void printP(Point const a, Point const b, Point const c, Point const point)
{
	std::cout<<BG<<"Vertice a:      "<<G;
	a.printPoint();
	std::cout<<BC<<std::endl<<"Vertice b:      "<<C;
	b.printPoint();
	std::cout<<BY<<std::endl<<"Vertice c:      "<<Y;
	c.printPoint();
	std::cout<<BM<<std::endl<<"Point to check: "<<M;
	point.printPoint();
	std::cout<<W<<std::endl<<std::endl;
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
	return (area);
	//Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By)
}

bool comparePoints(Point const a, Point const point){
	if (a.getX() == point.getX() && a.getY() == point.getY())
		return (true);
	return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed originalArea;
	Fixed area1;
	Fixed area2;
	Fixed area3;

	if (comparePoints(a, point) || comparePoints(b, point) || comparePoints(c, point))
		return (false);
	originalArea = area(a, b, c);
	area1 = area(point, a, b);
	area2 = area(point, b, c);
	area3 = area(point, a, c);
	if ((area1.toFloat() + area2.toFloat() + area3.toFloat()) == originalArea.toFloat())
		return (true);
	return (false);
}