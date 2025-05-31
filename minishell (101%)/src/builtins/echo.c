/* ************************************************************************** */
/*	  */
/*	::: ::::::::   */
/*   echo.c   :+:   :+: :+:   */
/*	+:+ +:+ +:+   */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+  */
/*	+#+#+#+#+#+   +#+  */
/*   Created: 2025/01/03 14:56:20 by bdenfir		   #+#  #+# */
/*   Updated: 2025/01/14 19:18:33 by bdenfir		  ###   ########.fr */
/*	  */
/* ************************************************************************** */

#include "minishell.h"

// Function to skip spaces in the input
char	*ft_skip_spaces(char *input)
{
	while (*input == ' ' || *input == '\t'
		|| *input == '\n' || *input == '\r' || *input == '\v' || *input == '\f')
		input++;
	return (input);
}

bool	ft_validate_n_flag(char **current, char quote_char, bool *n_flag)
{
	char	*temp;

	temp = *current + 1;
	while (*temp == 'n')
		temp++;
	if (*temp != ' ' && *temp != '\0' && *temp != quote_char)
		return (false);
	if (quote_char && *temp == quote_char)
		temp++;
	*n_flag = true;
	*current = ft_skip_spaces(temp);
	return (true);
}

bool	ft_check_n_flag(char **input)
{
	bool	n_flag;
	char	*current;
	char	quote_char;

	n_flag = false;
	current = *input;
	while (*current == '-' || *current == '\"' || *current == '\'')
	{
		quote_char = 0;
		if (*current == '\"' || *current == '\'')
		{
			quote_char = *current++;
			if (*current != '-')
				return (*input = *input, false);
		}
		if (!ft_validate_n_flag(&current, quote_char, &n_flag))
			return (*input = *input, false);
	}
	if (n_flag)
		*input = current;
	return (n_flag);
}

//Main function to implement the echo command
int	ft_echo(char *input)
{
	char	buffer[20000];
	bool	n_flag;

	if (!validate_command(input))
		return (KO);
	if (!input)
		return (printf("\n"));
	input = ft_skip_spaces(input);
	n_flag = ft_check_n_flag(&input);
	ft_process_input(input, buffer);
	if (!n_flag)
		printf("%s\n", buffer);
	else
		printf("%s", buffer);
	return (OK);
}
