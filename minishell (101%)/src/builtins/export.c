/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:39:48 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 10:28:34 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Prints error message for invalid export variable
int	print_export_error(int error, char *arg)
{
	if (error == -1)
		ft_putstr_fd("export: not valid in this context: ", STDERR_FILENO);
	while (*arg && (*arg != '=' || error == -3))
		write(STDERR_FILENO, arg++, 1);
	write(STDERR_FILENO, "\n", 1);
	return (STDERR_FILENO);
}

int	is_valid_varname(char *var)
{
	int	i;

	if (!(var[0] == '_' || ft_isalpha(var[0])))
		return (0);
	i = 1;
	while (var[i])
	{
		if (!(var[i] == '_' || ft_isalnum(var[i])))
			return (0);
		i++;
	}
	return (1);
}

void	handle_export_var(char *var_str, t_data *data)
{
	char	*equal_sign;
	char	*var;
	char	*value;

	equal_sign = ft_strchr(var_str, '=');
	if (equal_sign)
	{
		var = ft_substr(var_str, 0, equal_sign - var_str);
		value = equal_sign + 1;
		ft_set_env(var, value, data);
		if (!is_in_export_list(var, data->export))
			add_to_export(var_str, data);
		free(var);
	}
	else if (!is_in_export_list(var_str, data->export))
		add_to_export(var_str, data);
}

int	ft_export(char *str, t_data *data)
{
	char	**vars;
	int		i;

	if (!str || !*str)
		return (ft_env(data->envp, ""), 0);
	vars = ft_split(str, ' ');
	i = 0;
	while (vars[i])
		handle_export_var(vars[i++], data);
	free_args(vars);
	return (0);
}
