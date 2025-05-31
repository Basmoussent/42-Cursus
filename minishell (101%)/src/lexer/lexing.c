/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   lexing.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/12 15:17:30 by akassous		  #+#	#+#			 */
/*   Updated: 2025/02/24 19:50:23 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int	has_unclosed_quote(char *token)
{
	int	inside_single_quotes;
	int	inside_double_quotes;

	inside_double_quotes = 0;
	inside_single_quotes = 0;
	while (*token)
	{
		if (*token == '\'' && !inside_double_quotes)
			inside_single_quotes = !inside_single_quotes;
		else if (*token == '"' && !inside_single_quotes)
			inside_double_quotes = !inside_double_quotes;
		token++;
	}
	if (inside_single_quotes || inside_double_quotes)
	{
		ft_putstr_fd("error : unclosed quote\n", STDERR_FILENO);
		g_signal_received = 2;
		return (1);
	}
	return (0);
}

char	*get_last_token(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i + 1])
		i++;
	return (tokens[i]);
}

t_ast_node	*double_free_input(char	**args)
{
	int	i;

	if (!args)
		return (NULL);
	i = 0;
	while (args[i])
	{
		ft_free((void **)&args[i]);
		i++;
	}
	ft_free((void **)&args);
	args = NULL;
	return (NULL);
}

int	check_doubles(char **lexed_input)
{
	int	i;

	i = 0;
	while (lexed_input[i + 1])
	{
		if (is_special_char(lexed_input[i])
			&& is_special_char(lexed_input[i + 1]))
		{
			printf("minishell: syntax error near unexpected token %s\n",
				lexed_input[i + 1]);
			g_signal_received = 2;
			return (0);
		}
		i++;
	}
	if (is_special_char(lexed_input[i]))
	{
		printf("minishell: syntax error near unexpected token %s\n",
			lexed_input[i]);
		g_signal_received = 2;
		return (0);
	}
	return (1);
}

t_ast_node	*lexing(char *input, t_data *data)
{
	char		**first_input;
	char		**lexed_input;
	char		**true_input;
	t_ast_node	*ast;

	input = trim_input(input);
	if (!count_tokens(input))
		return (NULL);
	if (has_unclosed_quote(input))
		return (NULL);
	first_input = split_whitespace(input);
	lexed_input = fix_order(first_input);
	free_args(first_input);
	if (!lexed_input || !check_doubles(lexed_input))
		return (double_free_input(lexed_input));
	true_input = filter_tokens(lexed_input);
	if (!true_input)
		return (double_free_input(lexed_input));
	free_args(lexed_input);
	ast = parse_tokens(true_input, data);
	free_args(true_input);
	if (!ast)
		return (double_free_input(lexed_input));
	return (ast);
}
