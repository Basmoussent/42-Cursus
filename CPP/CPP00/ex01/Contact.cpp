/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:05:31 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/03 14:03:00 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <iostream>
Contact::Contact()
{
    // std::cout << "Default Constructor called" << std::endl;
}

Contact::Contact(std::string ff_name, std::string ll_name, std::string nn_name, std::string numberr, std::string secrett)
{
    f_name = ff_name;
    l_name = ll_name;
    n_name = nn_name;
    number = numberr;
    secret = secrett;
}

Contact::~Contact()
{
    // std::cout << "Destructor called for " << number << std::endl;
}

void Contact::display_contact()
{
    std::cout << std::setw(10) << format_string(f_name) << "|";
    std::cout << std::setw(10) << format_string(l_name) << "|";
    std::cout << std::setw(10) << format_string(n_name) << "|" << std::endl;
}

std::string Contact::format_string(const std::string& str)
{
    if (str.size() > 10)
        return str.substr(0, 9) + ".";
    return str;
}