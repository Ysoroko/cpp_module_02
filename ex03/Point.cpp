/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:46:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/02 14:12:40 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

//MyClass(int a) : x(a)
Point::Point(): x(0), y(0)
{
}

Point::~Point()
{
}
		
Point::Point(Point const & p): x(p.x), y(p.y)
{

}

Point::Point(float const x, float const y): x(x), y(y)
{
}

Point & Point::operator=( Point & rhs)
{
	return (rhs);
}

/// =
// Fixed & Fixed::operator=( Fixed const & rhs)
// {
// 	std::cout << "Assignation operator called" << std::endl;
// 	setRawBits(rhs.getRawBits());
// 	return (*this);
// }

//Point & Point::operator=( Point & rhs)
//{
//	Point	temp = rhs;
//
//	return (temp);
//}

Fixed	Point::getX( void ) const
{
	return (this->x);
}

Fixed	Point::getY( void ) const
{
	return (this->y);
}