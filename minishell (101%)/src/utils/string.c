/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   string.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/19 19:53:57 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/01/19 19:54:03 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

bool	validate_command(const char *cmd)
{
	bool	in_single_quote;
	bool	in_double_quote;

	in_single_quote = false;
	in_double_quote = false;
	if (!cmd)
		return (false);
	while (*cmd)
	{
		if (*cmd == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (*cmd == '\"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		else if (!in_single_quote && !in_double_quote && (*cmd == ';'
				|| *cmd == '&' || *cmd == '|' || *cmd == '<' || *cmd == '>'))
		{
			printf(COLOR_RED "unset: syntax error near unexpected token '%c'\n"
				COLOR_RESET, *cmd);
			return (false);
		}
		cmd++;
	}
	return (!in_single_quote && !in_double_quote);
}

// Function to process the input and remove quotes
void	ft_process_input(char *input, char *buffer)
{
	bool	in_single_quotes;
	bool	in_double_quotes;
	int		i;
	int		buffer_index;

	in_single_quotes = false;
	in_double_quotes = false;
	buffer_index = 0;
	i = -1;
	while (input[++i] != '\0')
	{
		if (input[i] == '\'' && !in_double_quotes)
		{
			in_single_quotes = !in_single_quotes;
			continue ;
		}
		if (input[i] == '"' && !in_single_quotes)
		{
			in_double_quotes = !in_double_quotes;
			continue ;
		}
		i += input[i] == '\\';
		buffer[buffer_index++] = input[i];
	}
	buffer[buffer_index] = '\0';
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		ft_free((void **)&args[i]);
		i++;
	}
	ft_free((void **)&args);
	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		ft_free((void **)&args[i]);
		i++;
	}
	ft_free((void **)&args);
	args = NULL;
}

void	free_ast(t_ast_node *node)
{
	if (!node)
		return ;
	free_ast(node->left);
	free_ast(node->right);
	ft_free((void **)&node->value);
	ft_free((void **)&node);
}

int	add_to_export(char *var, t_data *data)
{
	size_t	i;
	size_t	export_len;
	char	**new_export;

	export_len = 0;
	while (data->export && data->export[export_len])
		export_len++;
	new_export = malloc((export_len + 2) * sizeof(char *));
	if (!new_export)
		return (-1);
	i = -1;
	while (++i < export_len)
		new_export[i] = data->export[i];
	new_export[i] = ft_strdup(var);
	if (!new_export[i])
	{
		free(new_export);
		return (-1);
	}
	new_export[i + 1] = NULL;
	free(data->export);
	data->export = new_export;
	return (0);
}
