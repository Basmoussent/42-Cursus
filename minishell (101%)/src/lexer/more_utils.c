/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   more_utils.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/26 22:44:55 by amine			 #+#	#+#			 */
/*   Updated: 2025/03/01 08:14:41 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int	ft_fix(int *cmd_start, char **tokens, char **fix_tokens, int *i)
{
	if (cmd_start && tokens[*i] && tokens[*i + 1] && tokens[*i + 2]
		&& is_speci(tokens[*i]) && !is_speci(tokens[*i + 1])
		&& !is_speci(tokens[*i + 2]))
	{
		fix_tokens[*i] = ft_strdup(tokens[*i + 2]);
		fix_tokens[*i + 1] = ft_strdup(tokens[*i]);
		fix_tokens[*i + 2] = ft_strdup(tokens[*i + 1]);
		if (!fix_tokens[*i] || !fix_tokens[*i + 1] || !fix_tokens[*i + 2])
			return (-1);
		*i += 3;
		cmd_start = 0;
	}
	else
	{
		fix_tokens[*i] = ft_strdup(tokens[*i]);
		if (!fix_tokens[*i])
			return (-1);
		(*i)++;
		if (!is_speci(tokens[*i - 1]))
			cmd_start = 0;
	}
	return (0);
}

static char	**temp_loop(char **tokens, char **fix_tokens)
{
	int		i;
	int		cmd_start;

	i = 0;
	cmd_start = 1;
	while (tokens[i])
	{
		if (ft_strncmp(tokens[i], "|", 2) == 0)
		{
			fix_tokens[i] = ft_strdup(tokens[i]);
			if (!fix_tokens[i])
				return (NULL);
			cmd_start = 1;
			i++;
			continue ;
		}
		if (ft_fix(&cmd_start, tokens, fix_tokens, &i) == -1)
			return (NULL);
	}
	return (fix_tokens);
}

char	**fix_order(char **tokens)
{
	char	**fixed_tokens;
	int		count;

	count = count_tokens_array(tokens);
	fixed_tokens = malloc(sizeof(char *) * (count_tokens_array(tokens) + 1));
	if (!fixed_tokens)
	{
		return (NULL);
	}
	fixed_tokens = temp_loop(tokens, fixed_tokens);
	if (!fixed_tokens)
		return (NULL);
	fixed_tokens[count] = NULL;
	return (fixed_tokens);
}

char	*join_expand_pid(char *pid, char *input)
{
	char	*result;
	size_t	pid_len;
	size_t	input_len;

	if (*input == '"' || *input == '\'')
		return (pid);
	pid_len = ft_strlen(pid);
	input_len = ft_strlen(input);
	result = (char *)malloc(pid_len + input_len + 1);
	if (!result)
	{
		free(pid);
		return (NULL);
	}
	ft_strlcpy(result, pid, pid_len + 1);
	ft_strlcat(result, input, pid_len + input_len + 1);
	free(pid);
	return (result);
}

char	*join_expanded_pid(char *pid, char *input, char *str)
{
	char	*rslt;
	char	*status_str;
	char	*cpy;
	size_t	cpy_len;

	cpy_len = find_first_dollar(input);
	status_str = join_expand_pid(pid, str);
	if (!status_str)
		return (NULL);
	if (cpy_len > ft_strlen(input))
		cpy_len = 0;
	cpy = ft_strndup(input, cpy_len);
	if (!cpy)
	{
		free(status_str);
		return (NULL);
	}
	rslt = ft_strjoin(cpy, status_str);
	free(cpy);
	free(status_str);
	return (rslt);
}
