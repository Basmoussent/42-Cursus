/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:09:50 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/24 22:11:59 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Constructor
PhoneBook::PhoneBook() : nextIndex(0), size(0)
{
    // std::cout << "PhoneBook Constructor Called." << std::endl;
}

// Destructor
PhoneBook::~PhoneBook()
{
    // std::cout << "Destructor called for PhoneBook." << std::endl;
}

// Add a new contact to the phone book
void PhoneBook::AddContact(const Contact& newContact)
{
    list[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (size < 8)
        size++;
}

// Display all contacts in the phone book
void PhoneBook::DisplayPhoneBook()
{
    char input[256];
    int index;

    if (size == 0)
    {
        std::cout << "\033[31mYou currently have no contacts.\033[0m" << std::endl;
        return;
    }

    std::cout << "\033[32mYou currently have " << size << " contacts.\033[0m" << std::endl;
    std::cout << "\033[36m-------------------------------------\033[0m" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << "\033[33m[" << i + 1 << "] \033[0m";
        list[i].display_contact();
    }

    std::cout << "\033[36m-------------------------------------\033[0m" << std::endl;

    while (true)
    {
        std::cout << "\033[33mEnter the index of the contact you want to display: \033[0m";
        std::cin >> input;
        index = std::atoi(input);

        if (index < 1 || index > size)
        {
            std::cout << "\033[31mInvalid index... Try again.\033[0m" << std::endl;
            continue;
        }
        break;
    }

    std::cout << "\n\033[32mInformation for contact " << index << ":\033[0m" << std::endl;
    std::cout << "\033[36mFirst Name: \033[0m" << list[index - 1].f_name << std::endl;
    std::cout << "\033[36mLast Name: \033[0m" << list[index - 1].l_name << std::endl;
    std::cout << "\033[36mNickname: \033[0m" << list[index - 1].n_name << std::endl;
    std::cout << "\033[36mPhone Number: \033[0m" << list[index - 1].number << std::endl;
    std::cout << "\033[36mDarkest Secret: \033[0m" << list[index - 1].secret << std::endl;
}