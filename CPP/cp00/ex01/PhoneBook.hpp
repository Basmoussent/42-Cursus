/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:07:50 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/11 13:20:52 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

class PhoneBook {
private:
    Contact list[8];
    int nextIndex;

public:
    PhoneBook() : nextIndex(0) {
        std::cout << "PhoneBook Constructor Called." << std::endl;
    }

    void AddContact(const Contact& newContact)
	{
        
		list[nextIndex] = newContact;
        nextIndex = (nextIndex + 1) % 8;
    }

    void DisplayPhoneBook()
	{
        for (size_t i = 0; i < 8; i++)
		{
            if (!list[i].f_name.empty())
			{
                std::cout << "Contact [" << i + 1 << "]: ";
                list[i].display_contact();
            }
        }
    }

    ~PhoneBook() {
        std::cout << "Destructor called for PhoneBook." << std::endl;
    }
};
