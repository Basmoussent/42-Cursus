/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:34 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:22:29 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
putchar_fd will write the c character to the fd file descriptor.

write is defined as ; ssize_t write(int __fd, const void *__buf, size_t __n)

you already know standars fd's :
1 = standard output
2 = standard error output

By using the open function we can get the file descriptor
linked to any file so we can specifyt it in the fd parameter of
the write function adn write to it.
*/

void	ft_putchar_fd(char c, int fd)
{
	if (ft_isascii(c) && fd != -1)
		write(fd, &c, 1);
}
