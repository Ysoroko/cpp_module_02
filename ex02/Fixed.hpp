/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:08:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/30 15:42:47 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

// CANONIC FORM
// Class containing at least:
// 1) Constructor default
// 2) Copy constructor
// 3) '=' Operator overload
// 4) Destructor (virtual!)

class	Fixed
{
	public:
		// EX 00
		Fixed();
		~Fixed();

		// A copy constructor
		// A constructor which allows to create a copy of a different instance
		Fixed(Fixed const & src);

		// Operator '=' overload
		// rhs = right hand side, a constant reference to our oject instance
		// not a const function because our instance will be modified (ex: a = 14)
		// Returns a reference to allow us to do "a = b = c = d"
		Fixed & operator=( Fixed const & rhs);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
//-----------------------------------------------------------------------------------
		// EX 01
		Fixed(int const int_arg);
		Fixed(float const float_arg);

		float toFloat(void) const;
		int toInt(void) const;
//-----------------------------------------------------------------------------------
		// EX 02
		// > < >= <= == !=
		int operator>( Fixed const & rhs) const;
		int operator<( Fixed const & rhs) const;
		int operator>=( Fixed const & rhs) const;
		int operator<=( Fixed const & rhs) const;
		int operator==( Fixed const & rhs) const;
		int operator!=( Fixed const & rhs) const;
		
		// + - * /
		Fixed operator+( Fixed const & rhs) const;
		Fixed operator-( Fixed const & rhs) const;
		Fixed operator*( Fixed const & rhs) const;
		Fixed operator/( Fixed const & rhs) const;

		// ++F F++ --F F--
		Fixed & operator++( void ); // Prefix (++F)
		Fixed & operator--( void ); // Prefix (--F)
		Fixed & operator++( int n ); // Postfix (F++)
		Fixed & operator--( int n ); // Postfix (F--)

		// min & max
		static Fixed min(const Fixed & a, const Fixed & b );
		static Fixed max(const Fixed & a, const Fixed & b );

	private:
		int	fixed_point_value;
		static const int n_fract_bits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
