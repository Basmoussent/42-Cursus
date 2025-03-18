/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:33:56 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/24 22:14:01 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "header.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <limits>

class Contact
{
public:
    std::string f_name;
    std::string l_name;
    std::string n_name;
    std::string number;
    std::string secret;

    Contact();
    Contact(std::string ff_name, std::string ll_name, std::string nn_name, std::string numberr, std::string secrett);
    ~Contact();

    void display_contact();

private:
    std::string format_string(const std::string& str);
};