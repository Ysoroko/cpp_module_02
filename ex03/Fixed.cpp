/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:08:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/01 12:02:53 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016

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
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
	setRawBits(rhs.getRawBits());
	return (*this);
}

//-----------------------------------------------------------------------------------
// EX 01
//-----------------------------------------------------------------------------------

// INT constructor
Fixed::Fixed(int int_arg)
{
	setRawBits(int_arg << this->n_fract_bits);
}

// FLOAT constructor
// https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
// Calculate x = floating_input * 2^(fractional_bits)
// Round x to the nearest whole number (e.g. round(x))
// Store the rounded x in an integer container
Fixed::Fixed(float float_arg)
{
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
// EX 02
//-----------------------------------------------------------------------------------

// > < >= <= == !=
int Fixed::operator>( Fixed const & rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<( Fixed const & rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=( Fixed const & rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=( Fixed const & rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator==( Fixed const & rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=( Fixed const & rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (1);
	return (0);
}
//----------------

// + - * /
Fixed Fixed::operator+( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() + rhs.toFloat());
	
	return (ret);
}

Fixed Fixed::operator-( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() - rhs.toFloat());
	
	return (ret);
}

Fixed Fixed::operator*( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() * rhs.toFloat());
	
	return (ret);
}

Fixed Fixed::operator/( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() / rhs.toFloat());
	
	return (ret);
}

//----------------

// F++ ++F F-- --F
Fixed & Fixed::operator++( void ) // Prefix (++F)
{
	this->fixed_point_value += 1;
	return (*this);
}

Fixed & Fixed::operator--( void ) // Prefix (--F)
{
	this->fixed_point_value -= 1;
	return (*this);
}

Fixed Fixed::operator++( int ) // Postfix (F++)
{
	Fixed	temp = *this;

	(this->fixed_point_value) +=1 ;
	return (temp);
}

Fixed Fixed::operator--( int ) // Postfix (F--)
{
	Fixed	temp = *this;

	(this->fixed_point_value) -=1 ;
	return (temp);
}

//-----------------

// min & max

Fixed Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
	
Fixed Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
