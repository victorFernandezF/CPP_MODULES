/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:05:36 by victofer          #+#    #+#             */
/*   Updated: 2023/08/29 10:31:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(float const cx, float const cy);
		Point(const Point &copy);
		Point & operator=(const Point &copy);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
		void printPoint() const;
};

Fixed area(Point const a, Point const b, Point const c);
void printP(Point const a, Point const b, Point const c, Point const point);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif