/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:44:29 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/11 13:18:52 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main()
{
    PhoneBook book;

    // Adding 8 contacts manually
    book.AddContact(Contact("Alice", "Smith", "Ali", "111-111-1111", "Loves cats"));
    book.AddContact(Contact("Bob", "Johnson", "Bobby", "222-222-2222", "Hates pineapple pizza"));
    book.AddContact(Contact("Charlie", "Brown", "Chuck", "333-333-3333", "Secretly a spy"));
    book.AddContact(Contact("David", "White", "Dave", "444-444-4444", "Collects stamps"));
    book.AddContact(Contact("Eve", "Black", "Evie", "555-555-5555", "Has a twin"));
    book.AddContact(Contact("Frank", "Miller", "Frankie", "666-666-6666", "Can juggle"));
    book.AddContact(Contact("Grace", "Davis", "Gracie", "777-777-7777", "Loves puzzles"));
    book.AddContact(Contact("Hank", "Wilson", "Hanky", "888-888-8888", "Wants to be a magician"));

    std::cout << "\n--- PhoneBook After Adding 8 Contacts ---\n";
    book.DisplayPhoneBook();

    // Adding a 9th contact (should replace Alice)
    book.AddContact(Contact("Ivy", "Adams", "Ives", "999-999-9999", "Has a pet snake"));

    std::cout << "\n--- PhoneBook After Adding 9th Contact (Alice Should Be Replaced) ---\n";
    book.DisplayPhoneBook();

    return 0;
}

