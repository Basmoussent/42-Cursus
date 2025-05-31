/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:33 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/26 20:31:17 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long int	i;
	char				*str;

	str = (char *)s;
	i = -1;
	while (++i < n)
		str[i] = c;
	return (s);
}

/*
#include <stdio.h>
int main(){
	char	str[] = "ca marche le frere";
	printf(" 1 %s \n", str);
	ft_memset(str, 0, 18);
	printf("2 %s", str);
}
*/