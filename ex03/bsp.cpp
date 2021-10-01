/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:44:04 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/01 14:13:54 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// w1 = (Ax * (Cy - Ay)) + ((Py - Ay) * (Cx - Ax)) - (Px * (Cy - Ay))
//		---------------------------------------------------------------
//				(By - Ay)(Cx - Ax) - (Bx - Ax)(Cy - Ay)
Fixed	*get_w1( Point const a, Point const b, Point const c, Point const p)
{
	Point Acopy(a);
	Point Bcopy(b);
	Point Ccopy(c);
	Point Pcopy(p);
	Fixed Ax = Acopy.getX();
	Fixed Ay = Acopy.getY();
	Fixed Bx = Bcopy.getX();
	Fixed By = Bcopy.getY();
	Fixed Cx = Ccopy.getX();
	Fixed Cy = Ccopy.getY();
	Fixed Px = Pcopy.getX();
	Fixed Py = Pcopy.getY();

	Fixed *w1 = new Fixed(((Ax * (Cy - Ay)) + ((Py - Ay) * (Cx - Ax)) - (Px * (Cy - Ay))) / (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay));

	return (w1);
}

// w2 = Py - Ay - w1 * (By - Ay)
//		------------------------
//				Cy - Ay
Fixed	*get_w2( Fixed w1, Point const a, Point const b, Point const c, Point const p)
{
	Point Acopy(a);
	Point Bcopy(b);
	Point Ccopy(c);
	Point Pcopy(p);
	Fixed Ax = Acopy.getX();
	Fixed Ay = Acopy.getY();
	Fixed Bx = Bcopy.getX();
	Fixed By = Bcopy.getY();
	Fixed Cx = Ccopy.getX();
	Fixed Cy = Ccopy.getY();
	Fixed Px = Pcopy.getX();
	Fixed Py = Pcopy.getY();

	Fixed *w2 = new Fixed((Py - Ay - w1 * (Ay - Ay)) / Cy - Ay);

	return (w2);
}

// The return value is True if the point is inside the triangle
// otherwise, the return value should be False.
// This means that if the point is a vertex or a point that is
// on the edge, the return value should be False
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed *w1 = get_w1(a, b, c, point);
	Fixed *w2 = get_w2(*w1, a, b, c, point);
	bool	ret;

	if (*w1 > 0 && *w2 > 0 && (*w1 + *w2) < 1)
		ret = true;
	else
		ret = false;
	delete w1;
	delete w2;
	return (ret);
}
