/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:39:48 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/24 19:17:18 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_var_value(char *var, char *value)
{
	char	*new_entry;
	char	*full_entry;

	new_entry = ft_strjoin(var, "=");
	if (!new_entry)
		return (NULL);
	full_entry = ft_strjoin(new_entry, value);
	free(new_entry);
	return (full_entry);
}

int	add_new_var_to_env(char *full_entry, t_data *data)
{
	size_t	env_len;
	char	**new_envp;
	size_t	i;

	env_len = 0;
	while (data->envp[env_len])
		env_len++;
	new_envp = malloc((env_len + 2) * sizeof(char *));
	if (!new_envp)
	{
		free(full_entry);
		return (-1);
	}
	i = 0;
	while (i < env_len)
	{
		new_envp[i] = data->envp[i];
		i++;
	}
	new_envp[i] = full_entry;
	new_envp[i + 1] = NULL;
	free(data->envp);
	data->envp = new_envp;
	return (0);
}

static char	**init_minimal_env(void)
{
	char	**env_copy;
	char	*cwd;

	env_copy = malloc(4 * sizeof(char *));
	if (!env_copy)
		return (NULL);
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (free(env_copy), NULL);
	env_copy[0] = ft_strjoin("PWD=", cwd);
	env_copy[1] = ft_strdup("SHLVL=1");
	env_copy[2] = ft_strdup("_=/usr/bin/env");
	env_copy[3] = NULL;
	free(cwd);
	if (!env_copy[0] || !env_copy[1])
		return (free_args(env_copy), NULL);
	return (env_copy);
}

char	**copy_existing_env(char **envp)
{
	char	**env_copy;
	int		i;
	int		len;

	len = 0;
	while (envp[len])
		len++;
	env_copy = malloc((len + 1) * sizeof(char *));
	if (!env_copy)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		env_copy[i] = ft_strdup(envp[i]);
		if (!env_copy[i])
			return (free_args(env_copy), NULL);
	}
	env_copy[i] = NULL;
	return (env_copy);
}

char	**copy_envp(char **envp)
{
	if (!envp || !*envp)
		return (init_minimal_env());
	return (copy_existing_env(envp));
}
