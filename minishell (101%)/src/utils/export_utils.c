/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:39:48 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 10:38:06 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_set_env(char *var, char *value, t_data *data)
{
	size_t	i;
	char	*full_entry;

	if (!var || !value || !data || !data->envp)
		return (-1);
	if (!is_valid_varname(var))
		return (print_export_error(-1, var));
	full_entry = join_var_value(var, value);
	if (!full_entry)
		return (-1);
	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], var, ft_strlen(var)) == 0
			&& data->envp[i][ft_strlen(var)] == '=')
		{
			free(data->envp[i]);
			data->envp[i] = full_entry;
			return (0);
		}
		i++;
	}
	return (add_new_var_to_env(full_entry, data));
}

void	print_export_list(char **export_list)
{
	int		i;
	char	*equal_sign;
	char	*var;
	char	*value;

	if (!export_list)
		return ;
	i = -1;
	while (export_list[++i])
	{
		equal_sign = ft_strchr(export_list[i], '=');
		if (equal_sign)
		{
			var = ft_strndup(export_list[i], equal_sign - export_list[i]);
			value = equal_sign + 1;
			printf("export %s=\"%s\"\n", var, value);
			free(var);
		}
		else
			printf("export %s\n", export_list[i]);
	}
}

int	is_in_export_list(char *var, char **export_list)
{
	int		i;
	size_t	var_len;

	if (!var || !export_list)
		return (0);
	var_len = ft_strlen(var);
	i = 0;
	while (export_list[i])
	{
		if (ft_strncmp(export_list[i], var, var_len) == 0
			&& (export_list[i][var_len] == '='
			|| export_list[i][var_len] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

static char	**init_minimal_export(void)
{
	char	**export_copy;
	char	*cwd;

	export_copy = malloc(4 * sizeof(char *));
	if (!export_copy)
		return (NULL);
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (free(export_copy), NULL);
	export_copy[0] = ft_strjoin("PWD=", cwd);
	export_copy[1] = ft_strdup("SHLVL=1");
	export_copy[2] = ft_strdup("OLDPWD");
	export_copy[3] = NULL;
	free(cwd);
	if (!export_copy[0] || !export_copy[1] || !export_copy[2])
		return (free_args(export_copy), NULL);
	return (export_copy);
}

char	**copy_export_list(char **envp)
{
	if (!envp || !*envp)
		return (init_minimal_export());
	return (copy_existing_env(envp));
}
