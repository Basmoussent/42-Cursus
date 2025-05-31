/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:17:00 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 14:40:22 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **envp, char *arg)
{
	int	i;

	if (!envp || !*envp)
		return (KO);
	if (ft_strcmp(arg, ""))
		return (printf("env: '%s': No such file or directory\n", arg));
	i = -1;
	while (envp[++i])
		printf("%s\n", envp[i]);
	return (OK);
}
