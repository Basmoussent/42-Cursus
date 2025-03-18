/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:31:11 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/18 12:47:27 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
	int				_value;
	static const int _factor;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed&operator=(const Fixed& other);
		
	bool operator>(Fixed fixed)const;
	bool operator<(Fixed fixed)const;
	bool operator>=(Fixed fixed)const;
	bool operator<=(Fixed fixed)const;
	bool operator==(Fixed fixed)const;
	bool operator!=(Fixed fixed)const;

	float operator+(Fixed fixed)const;
	float operator-(Fixed fixed)const;
	float operator*(Fixed fixed)const;
	float operator/(Fixed fixed)const;

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


