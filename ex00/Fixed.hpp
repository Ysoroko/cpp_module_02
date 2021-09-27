/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:08:20 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/27 14:14:54 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
		int	fixed_point_value;
		static const int n_fract_bits;

	private:
		Fixed();
		~Fixed();
		// A copy constructor
		// An assignation operator overload
		int getRawBits( void ) const;
		void setRawBits( int const raw );

};
#endif