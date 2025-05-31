/* ************************************************************************** */
/*	                                                                    */
/*                                                        :::      ::::::::   */
/*   trim_and_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:35:30 by amine             #+#    #+#             */
/*   Updated: 2025/02/18 13:24:08 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_spe(char **input, int *token_count)
{
	if ((*input)[0] == '>' && (*input)[1] == '>')
	{
		*input += 2;
		(*token_count)++;
		return (1);
	}
	if ((*input)[0] == '<' && (*input)[1] == '<')
	{
		*input += 2;
		(*token_count)++;
		return (1);
	}
	if ((*input)[0] == '|' || (*input)[0] == '<' || (*input)[0] == '>')
	{
		(*input)++;
		(*token_count)++;
		return (1);
	}
	return (0);
}

char	*get_next_quote(char *input, int is_double_qte)
{
	char	sep;

	if (is_double_qte)
		sep = '"';
	else
		sep = '\'';
	while (*input && *input != sep)
		input++;
	if (*input == sep)
		input++;
	return (input);
}

int	count_tokens(char *input)
{
	int	token_count;

	token_count = 0;
	while (*input && is_space(*input))
		input++;
	while (*input)
	{
		while (*input && is_space(*input))
			input++;
		if (*input == '\0')
			break ;
		if (is_spe(&input, &token_count))
			continue ;
		if (*input == '\'')
			input = get_next_quote(input + 1, 0);
		else if (*input == '"')
			input = get_next_quote(input + 1, 1);
		else
		{
			while (*input && !isspace(*input) && !is_spe(&input, &token_count))
				input++;
		}
		token_count++;
	}
	return (token_count);
}

char	*trim_input(char *input)
{
	char	*end;

	while (is_space((unsigned char)*input))
		input++;
	if (*input == 0)
		return (input);
	end = input + ft_strlen(input) - 1;
	while (end > input && is_space((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (input);
}
