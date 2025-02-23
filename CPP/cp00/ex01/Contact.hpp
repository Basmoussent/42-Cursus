/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:33:56 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/11 13:21:18 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

class Contact
{
	public:
		std::string f_name;
		std::string l_name;
		std::string n_name;
		std::string number;
		std::string secret;
	
	Contact()
	{
		std::cout << "Default constructor called but all infos arent specified" << std::endl;
	}
	
	Contact(std::string ff_name, std::string ll_name, std::string nn_name, std::string numberr, std::string secrett)
	{
		std::cout << "Contact Constructor called" << std::endl;

		f_name = ff_name;
		l_name = ll_name;
		n_name = nn_name;
		number = numberr;
		secret = secrett;
	}

	~Contact()
	{
		std::cout << "destructor called for " << number << std::endl;
	}

    void display_contact()
    {
        std::cout << std::setw(10);
  		std::cout << f_name << "|";
        std::cout << std::setw(10);
		std::cout << l_name << "|";
        std::cout << std::setw(10);
		std::cout << n_name << "|";
        std::cout << std::setw(10);
		std::cout << number << "|";
        std::cout << std::setw(10);
		std::cout << secret << "|";
		std::cout << std::endl; 
    }
};