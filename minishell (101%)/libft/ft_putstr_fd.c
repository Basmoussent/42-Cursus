/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:38 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:22:09 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
putstr_fd will write a string to a specific file descriptor
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd != -1)
		write(fd, s, ft_strlen(s));
}
