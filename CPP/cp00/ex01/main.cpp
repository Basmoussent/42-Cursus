/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:44:29 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/24 22:09:16 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int main()
{
    char options[256];
    PhoneBook book;
    
    book.AddContact(Contact("Alice", "Smith", "Ali", "111-111-1111", "Loves cats"));
    book.AddContact(Contact("Bob", "Johnson", "Bobby", "222-222-2222", "Hates pineapple pizza"));
    book.AddContact(Contact("Charlie", "Brown", "Chuck", "333-333-3333", "Secretly a spy"));
    book.AddContact(Contact("David", "White", "Dave", "444-444-4444", "Collects stamps"));

    while (true)
    {
        std::cout << "\n\033[33mPlease enter a command: \033[0m";
        std::cout << "\033[36mADD, SEARCH or EXIT\033[0m" << std::endl;
        std::cin >> options;

        if (std::string(options) == "EXIT")
        {
            std::cout << "\033[32mExiting program. Goodbye!\033[0m" << std::endl;
            break;
        }
        else if (std::string(options) == "ADD")
        {
            std::string f_name, l_name, n_name, number, secret;

            std::cout << "\033[33mPlease enter the first name: \033[0m";
            std::cin >> f_name;
            std::cout << "\033[33mPlease enter the last name: \033[0m";
            std::cin >> l_name;
            std::cout << "\033[33mPlease enter the nickname: \033[0m";
            std::cin >> n_name;
            std::cout << "\033[33mPlease enter the phone number: \033[0m";
            std::cin >> number;
            std::cout << "\033[33mPlease enter the darkest secret: \033[0m";
            std::cin >> secret;
            Contact newContact(f_name, l_name, n_name, number, secret);
            book.AddContact(newContact);
            std::cout << "\033[32mContact has successfully been created!\033[0m" << std::endl;
        }
        else if (std::string(options) == "SEARCH")
            book.DisplayPhoneBook();
        else
            std::cout << "\033[31mInvalid command. Please try again.\033[0m" << std::endl;
    }

    return 0;
}

// int main()
// {
//     PhoneBook book;

//     // Adding 8 contacts manually
//     book.AddContact(Contact("Alice", "Smith", "Ali", "111-111-1111", "Loves cats"));
//     book.AddContact(Contact("Bob", "Johnson", "Bobby", "222-222-2222", "Hates pineapple pizza"));
//     book.AddContact(Contact("Charlie", "Brown", "Chuck", "333-333-3333", "Secretly a spy"));
//     book.AddContact(Contact("David", "White", "Dave", "444-444-4444", "Collects stamps"));
//     book.AddContact(Contact("Eve", "Black", "Evie", "555-555-5555", "Has a twin"));
//     book.AddContact(Contact("Frank", "Miller", "Frankie", "666-666-6666", "Can juggle"));
//     book.AddContact(Contact("Grace", "Davis", "Gracie", "777-777-7777", "Loves puzzles"));
//     book.AddContact(Contact("Hank", "Wilson", "Hanky", "888-888-8888", "Wants to be a magician"));

//     book.DisplayPhoneBook();

//     // Adding a 9th contact (should replace Alice)
//     book.AddContact(Contact("Ivy", "Adams", "Ives", "999-999-9999", "Has a pet snake"));

//     book.DisplayPhoneBook();

//     return 0;
// }

