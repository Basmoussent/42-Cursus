/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   expanding.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/18 13:13:56 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/02/25 17:26:35 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char *name, t_data *data)
{
	int		i;
	size_t	len;

	len = ft_strlen(name);
	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], name, len) == 0
			&& data->envp[i][len] == '=')
			return (data->envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

char	*extract_var_name(char *start)
{
	char	*end;
	char	*value;

	end = start + 1;
	while (*end && (ft_isalnum(*end) || *end == '_'))
		end++;
	value = ft_strndup(start + 1, end - start - 1);
	if (!value)
		return (NULL);
	return (value);
}

char	*replace_variable(char *input, char *start, char *var_value, char *end)
{
	size_t	len;
	char	*result;

	len = ft_strlen(input) - (end - start) + ft_strlen(var_value);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, input, start - input + 1);
	result[start - input] = '\0';
	ft_strlcat(result, var_value, len + 1);
	ft_strlcat(result, end, len + 1);
	return (result);
}

char	*expand_single_variable(char *input, t_data *data)
{
	char	*start;
	char	*end;
	char	*var_name;
	char	*var_value;
	char	*result;

	start = ft_strchr(input, '$');
	if (!start)
		return (ft_strdup(input));
	end = start + 1;
	if (*end == '\'' || *end == '"')
		return (ft_strdup_without_dollar(input, start));
	if (*end == '?')
		return (join_expanded_status(g_signal_received, input, end + 1));
	if (*end == '$')
		return (join_expanded_pid(expand_pid(data), input, end + 1));
	while (*end && (ft_isalnum(*end) || *end == '_'))
		end++;
	var_name = extract_var_name(start);
	var_value = get_env_value(var_name, data);
	free(var_name);
	if (!var_value)
		var_value = "";
	result = replace_variable(input, start, var_value, end);
	return (result);
}

char	*expand_all_variables(char *input, t_data *data)
{
	char	*result;

	result = ft_strdup(input);
	if (!result)
		return (NULL);
	return (process_variables(result, data));
}
