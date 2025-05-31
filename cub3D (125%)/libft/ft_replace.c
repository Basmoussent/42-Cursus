/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:24:15 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/04 13:24:17 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_replace(char *str, const char *charset, char replace_char)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (charset[j] != '\0')
		{
			if (str[i] == charset[j])
			{
				str[i] = replace_char;
				break ;
			}
			j++;
		}
		i++;
	}
}
