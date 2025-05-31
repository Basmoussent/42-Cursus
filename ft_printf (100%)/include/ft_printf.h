/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:00:24 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/22 04:01:51 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putnbr_fd(int nb);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int		handle_conversion(const char *conversion, va_list args, void *ptr);
char	*ft_utoa(unsigned int n);
int		handle_integer(int c);
int		int_length(int n);
int		handle_char(int c);
int		handle_string(char *str);
int		handle_base(unsigned long n, const char *base);
int		handle_unsigned(unsigned int value);
void	ft_putstr_fd(char *s);

#endif