/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:47:19 by amine             #+#    #+#             */
/*   Updated: 2025/03/01 11:10:43 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_speci(char *token)
{
	if (*token)
		return (token[0] == '>' || token[0] == '<'
			|| ft_strncmp(token, ">>", 2) == 0);
	return (KO);
}

int	count_tokens_array(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

char	**allocate_filtered_tokens(char **tokens)
{
	char	**filtered_tokens;

	filtered_tokens = malloc(sizeof(char *) * (count_tokens_array(tokens) + 1));
	if (!filtered_tokens)
		return (NULL);
	return (filtered_tokens);
}

char	**allocate_ignored_tokens(char **tokens)
{
	char	**ignored_tokens;

	ignored_tokens = malloc(sizeof(char *) * (count_tokens_array(tokens) + 1));
	if (!ignored_tokens)
		return (NULL);
	return (ignored_tokens);
}

int	found_builtin(char *input)
{
	return (input[0] == '|' || input[0] == '>' || input[0] == '<');
}
