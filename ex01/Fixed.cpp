/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:08:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/30 11:03:04 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor called
// Int constructor called
// Float constructor called
// Copy constructor called
// Assignation operator called
// Float constructor called
// Assignation operator called
// Destructor called
// a is 1234.43
// b is 10
// c is 42.4219
// d is 10
// a is 1234 as integer
// b is 10 as integer
// c is 42 as integer
// d is 10 as integer
// Destructor called
// Destructor called
// Destructor called
// Destructor called


/* Fixed a;
Fixed const b(10);
Fixed const c(42.42f);
Fixed const d(b);
a = Fixed(1234.4321f);
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl; */

int Fixed::getRawBits( void ) const
{
	return (this->fixed_point_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->fixed_point_value = raw;
}

Fixed::Fixed()
{
	this->fixed_point_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return (*this);
}

// INT constructor
Fixed::Fixed(int int_arg)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(int_arg);
}

// FLOAT constructor
// https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
// Calculate x = floating_input * 2^(fractional_bits)
// Round x to the nearest whole number (e.g. round(x))
// Store the rounded x in an integer container
Fixed::Fixed(float float_arg)
{
	float	x = float_arg * (2^(this->n_fract_bits));
	int		y = roundf(x);

	this->setRawBits(y);
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = static_cast<int>(float_arg);
}

// We take the input value and divide it by (2fractional_bits), putting the result into a float
float Fixed::toFloat(void) const
{
	return ((double)this->getRawBits() / (double)(1 << this->n_fract_bits));
}

//fix >> FIXED_POINT
int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->n_fract_bits);
}

// << operator overload (not a member function!)
std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	std::string dot = "";
	std::string str = "";
	if (rhs.toInt())
	{
		dot = ".";
		str = std::to_string(rhs.toInt());
	}
	o << rhs.getRawBits() << dot << str;
	return (o);
}
