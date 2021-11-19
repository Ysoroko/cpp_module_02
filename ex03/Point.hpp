/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:39:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/11/19 14:04:09 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		~Point();
		Point(Point const & p);
		Point(float const x, float const y);
		Point(Fixed const x, Fixed const y);
		Point & operator=( Point & rhs);
		void	setX(Fixed f);
		void	setY(Fixed f);
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

	private:
		Fixed	const x;
		Fixed	const y;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif