/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:08:42 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/22 03:56:51 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// typedef int(*t_converter)(va_list);
// typedef struct s_conversion t_conversion;
// struct s_conversion {
// 	char const			identifier;
// 	t_converter const	converter;
// };
// static t_conversion const	g_conversions[] = {
// { .identifier = 'c', .converter = convert_char },
// { .identifier = 's', .converter = convert_string }
// { .identifier = 'd', .converter = convert_int },
// { .identifier = 'i', .converter = convert_int },
// { .identifier = 'u', .converter = convert_unsinged_int_decimal },
// { .identifier = 'x', .converter = convert_unsigned_int_upper_hexadecimal },
// { .identifier = 'X', .converter = convert_unsigned_int_lower_hexadecimal },
// { .identifier = 'o', .converter = convert_unsigned_int_octal },
// { .identifier = 'p', .converter = convert_pointer },
// { .identifier = '%', .converter = convert_percen },
// };

int	handle_base(unsigned long n, const char *base)
{
	char			*str;
	int				len;
	unsigned long	tmp;

	len = 1;
	tmp = n;
	while (tmp >= ft_strlen(base))
	{
		len++;
		tmp /= ft_strlen(base);
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	write(1, str, ft_strlen(str));
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	handle_conversion(const char *conversion, va_list args, void *ptr)
{
	if (*conversion == 'd' || *conversion == 'i')
		return (handle_integer(va_arg(args, int)));
	else if (*conversion == 's')
		return (handle_string(va_arg(args, char *)));
	else if (*conversion == 'c')
		return (handle_char(va_arg(args, int)));
	else if (*conversion == 'x')
		return (handle_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*conversion == 'X')
		return (handle_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*conversion == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	else if (*conversion == 'o')
		return (handle_base(va_arg(args, unsigned int), "01234567"));
	else if (*conversion == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + handle_base((unsigned long)ptr,
				"0123456789abcdef"));
	}
	else if (*conversion == '%')
		return (handle_char('%'));
	return (0);
}
