/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:05:36 by victofer          #+#    #+#             */
/*   Updated: 2023/08/07 11:00:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
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
		Point(Point &copy);
		Point & operator=(const Point &copy);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

Fixed area(Point const a, Point const b, Point const c);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif