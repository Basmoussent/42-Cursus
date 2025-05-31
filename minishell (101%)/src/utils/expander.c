/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   expander.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/24 20:08:14 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/02/24 20:08:23 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

void	handle_double_quote(bool *in_quotes, size_t *i)
{
	*in_quotes = !*in_quotes;
	(*i)++;
}

void	skip_single_quotes(char *result, size_t *i)
{
	*i += 2;
	while (result[*i] && result[*i] != '\'')
		(*i)++;
	if (result[*i])
		(*i)++;
}

char	*handle_expansion(char *result, t_data *data, size_t *i)
{
	char	*temp;

	temp = expand_single_variable(result, data);
	free(result);
	*i = 0;
	return (temp);
}

char	*process_variables(char *result, t_data *data)
{
	bool	in_quotes;
	size_t	i;

	in_quotes = false;
	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] == '"')
		{
			handle_double_quote(&in_quotes, &i);
			continue ;
		}
		if (!in_quotes && result[i] == '\'' && result[i + 1])
		{
			skip_single_quotes(result, &i);
			continue ;
		}
		if (result[i] == '$' && can_expand(&result[i]))
			result = handle_expansion(result, data, &i);
		else
			i++;
	}
	return (result);
}

char	*expand_pid(t_data *data)
{
	pid_t	pgrp;

	if (ioctl(data->original_stdin, TIOCGPGRP, &pgrp) == -1)
	{
		perror("ioctl TIOCGPGRP failed");
		return (NULL);
	}
	return (ft_itoa(pgrp));
}
