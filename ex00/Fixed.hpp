/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:08:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/28 15:52:58 by ysoroko          ###   ########.fr       */
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

	private:
		int	fixed_point_value;
		static const int n_fract_bits = 8;
};

#endif
