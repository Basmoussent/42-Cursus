/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:07:50 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/24 22:14:39 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "header.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <limits>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact list[8];
        int nextIndex;
        int size;
    
    public:
        PhoneBook();
        ~PhoneBook();
    
        void AddContact(const Contact& newContact);
        void DisplayPhoneBook();
};