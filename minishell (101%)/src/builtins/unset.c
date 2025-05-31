/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:20:44 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 10:50:18 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function to check if the argument is a valid variable name
int	unset_it(const char *var, t_data *data)
{
	int		i;
	int		j;
	int		len;
	char	**new_envp;

	if (!var || !data || !data->envp)
		return (-1);
	len = ft_strlen(var);
	new_envp = malloc(sizeof(char *) * 1024);
	if (!new_envp)
		return (-1);
	i = -1;
	j = 0;
	while (data->envp[++i])
	{
		if (ft_strncmp(data->envp[i], var, len) == 0
			&& data->envp[i][len] == '=')
			free(data->envp[i]);
		else
			new_envp[j++] = data->envp[i];
	}
	new_envp[j] = NULL;
	free(data->envp);
	data->envp = new_envp;
	return (0);
}

// Function to check if the argument is a valid variable name
void	check_args(char *arg, int *ret, t_data *data)
{
	ft_process_input(arg, arg);
	if (!arg || occur(arg, '=') != 0)
	{
		printf(COLOR_RED "unset: '%s': invalid parameter\n" COLOR_RESET, arg);
		*ret = KO;
	}
	else if (is_valid_varname(arg))
	{
		if (unset_it(arg, data) != 0)
		{
			printf(COLOR_RED "unset: Failed to unset '%s'\n" COLOR_RESET, arg);
			*ret = KO;
		}
	}
	else
		*ret = KO;
}

// Function to process the arguments
int	ft_unset_process_args(char **args, t_data *data)
{
	int	i;
	int	ret;

	ret = OK;
	i = -1;
	while (args[++i])
		check_args(args[i], &ret, data);
	return (ret);
}

// Function to unset a variable
int	ft_unset(char *input, t_data *data)
{
	char	**args;
	int		ret;
	char	*buffer;

	if (!input || !data || !data->envp || !validate_command(input))
		return (KO);
	buffer = ft_strtrim(input, " ");
	if (!buffer)
		return (KO);
	args = ft_split(buffer, ' ');
	free(buffer);
	if (!args || !args[0])
	{
		free_args(args);
		return (KO);
	}
	ret = ft_unset_process_args(args, data);
	free_args(args);
	return (ret);
}
