/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:00:28 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/30 16:09:24 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		lenght;

	va_start(args, format);
	lenght = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			lenght += handle_conversion(format, args);
		}
		else
		{
			lenght++;
			write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (lenght);
}
