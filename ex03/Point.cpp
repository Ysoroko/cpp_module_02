/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:46:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/01 12:07:35 by ysoroko          ###   ########.fr       */
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
	
}

