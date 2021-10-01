/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:39:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/01 12:10:34 by ysoroko          ###   ########.fr       */
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
		Point & operator=( Point & rhs);
		void	setX(Fixed f);
		void	setY(Fixed f);
		Fixed	getX( void );
		Fixed	getY( void );

	private:
		Fixed	const x;
		Fixed	const y;
};


#endif