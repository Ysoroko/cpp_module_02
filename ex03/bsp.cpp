/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:44:04 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/01 16:46:50 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// w1 = vector proportion of the first side of triangle
// w1 = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay))
//		---------------------------------------------------------------
//				(By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay)
Fixed	*get_w1( Point const a, Point const b, Point const c, Point const p)
{
	Point Acopy(a);
	Point Bcopy(b);
	Point Ccopy(c);
	Point Pcopy(p);
	float Ax = Acopy.getX().toFloat();
	float Ay = Acopy.getY().toFloat();
	float Bx = Bcopy.getX().toFloat();
	float By = Bcopy.getY().toFloat();
	float Cx = Ccopy.getX().toFloat();
	float Cy = Ccopy.getY().toFloat();
	float Px = Pcopy.getX().toFloat();
	float Py = Pcopy.getY().toFloat();

	//std::cout << "Ax: " << Ax << " Ay: " << Ay << " Bx: " << Bx << " By: " << By << " Cx: " << Cx << " Cy: " << Cy << std::endl;

	float	num = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
	float	denum = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
	float	f = num / denum;
	Fixed *w1 = new Fixed(f);

	return (w1);
}

// w2 = vector proportion of the second side of triangle
// w2 = Py - Ay - w1 * (By - Ay)
//		------------------------
//				Cy - Ay
Fixed	*get_w2( Fixed w1, Point const a, Point const b, Point const c, Point const p)
{
	Point Acopy(a);
	Point Bcopy(b);
	Point Ccopy(c);
	Point Pcopy(p);
	float Ay = Acopy.getY().toFloat();
	float By = Bcopy.getY().toFloat();
	float Cy = Ccopy.getY().toFloat();
	float Py = Pcopy.getY().toFloat();

	float w = w1.toFloat();

	float	num = Py - Ay - w * (By - Ay);
	float	denum = Cy - Ay;
	Fixed *w2 = new Fixed(num / denum);

	return (w2);
}

// The return value is True if the point is inside the triangle
// otherwise, the return value should be False.
// This means that if the point is a vertex or a point that is
// on the edge, the return value should be False
// Formula used from: https://www.youtube.com/watch?v=HYAgJN3x4GA
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed *w1 = get_w1(a, b, c, point);
	Fixed *w2 = get_w2(*w1, a, b, c, point);
	//std::cout << "W1: " << *w1 << " W2: " << *w2 << std::endl;
	bool	ret = true;

	if (*w1 > 0 && *w2 > 0 && (*w1 + *w2) < 1)
		ret = true;
	else
		ret = false;
	delete w1;
	delete w2;
	return (ret);
}
