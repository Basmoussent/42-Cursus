/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:09:22 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 01:57:44 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_data *data)
{
	int	i;

	if (!data->envp || !*data->envp)
		return (KO);
	i = 0;
	while (data->envp[i] && ft_strnstr(data->envp[i], "PWD", 3) == 0)
		i++;
	printf("%s\n", ft_strchr(data->envp[i], '/'));
	return (OK);
}
