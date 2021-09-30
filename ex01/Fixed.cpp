/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:08:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/30 13:59:50 by ysoroko          ###   ########.fr       */
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

//-----------------------------------------------------------------------------------
// EX 01
//-----------------------------------------------------------------------------------

// INT constructor
Fixed::Fixed(int int_arg)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(int_arg << this->n_fract_bits);
}

// FLOAT constructor
// https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
// Calculate x = floating_input * 2^(fractional_bits)
// Round x to the nearest whole number (e.g. round(x))
// Store the rounded x in an integer container
Fixed::Fixed(float float_arg)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_arg * (1 << this->n_fract_bits)));
}

// We take the input value and divide it by (2fractional_bits), putting the result into a float
float Fixed::toFloat(void) const
{
	float	f;

	f = (float)this->getRawBits() / (1 << this->n_fract_bits);
	return (f);
}

//fix >> FIXED_POINT
int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->n_fract_bits);
}

// << operator overload (not a member function!)
std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	//std::cout << std:: endl << "RAW: " << rhs.getRawBits() << std::endl;
	//std::cout << std:: endl << "TOINT: " << rhs.toInt() << std::endl;
	//std::cout << std:: endl << "TOFLOAT: " << rhs.toFloat() << std::endl;
	return (o);
}

//-----------------------------------------------------------------------------------
