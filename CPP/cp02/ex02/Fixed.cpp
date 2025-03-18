/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:40:35 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/18 12:53:11 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "cmath"

const int Fixed::_factor = 8;

Fixed::Fixed(): _value(0)
{
	//std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value)
{
	this->_value = value << this->_factor;
}
Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_factor));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void)const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}
void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_factor));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_factor);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}


bool Fixed::operator>(Fixed fixed)const
{
	return (this->toFloat() > fixed.toFloat());
}
bool Fixed::operator<(Fixed fixed)const
{
	return (this->toFloat() < fixed.toFloat());
}
bool Fixed::operator>=(Fixed fixed)const
{
	return (this->toFloat() >= fixed.toFloat());
}
bool Fixed::operator<=(Fixed fixed)const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed)const
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed)const
{
	return (this->toFloat() != fixed.toFloat());
}

float Fixed::operator+(Fixed fixed)const
{
	return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed fixed)const
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(Fixed fixed)const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed& b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed& b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}


