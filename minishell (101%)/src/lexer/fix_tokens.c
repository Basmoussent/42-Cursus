/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:04:11 by amine             #+#    #+#             */
/*   Updated: 2025/02/17 20:28:58 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_files_from_ignored_tokens(char **ignored_tokens)
{
	int	i;
	int	fd;

	i = 0;
	while (ignored_tokens[i])
	{
		if (ignored_tokens[i][0] != '>')
		{
			fd = open(ignored_tokens[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				;
			else
				close(fd);
		}
		i++;
	}
}

void	add_last_redirection(t_token_processing *tp)
{
	if (tp->last_redirection && tp->last_target)
	{
		tp->filtered_tokens[tp->j++] = ft_strdup(tp->last_redirection);
		tp->filtered_tokens[tp->j++] = ft_strdup(tp->last_target);
		tp->last_redirection = NULL;
		tp->last_target = NULL;
	}
}

void	process_tokens(t_token_processing *tp)
{
	while (tp->tokens[tp->i])
	{
		if (is_speci(tp->tokens[tp->i]))
		{
			if (tp->last_redirection && tp->last_target)
			{
				tp->ignored_tokens[tp->k++] = ft_strdup(tp->last_redirection);
				tp->ignored_tokens[tp->k++] = ft_strdup(tp->last_target);
			}
			tp->last_redirection = tp->tokens[tp->i];
			if (tp->tokens[tp->i + 1])
				tp->last_target = tp->tokens[tp->i + 1];
			tp->i += 2;
		}
		else
		{
			add_last_redirection(tp);
			tp->filtered_tokens[tp->j++] = ft_strdup(tp->tokens[tp->i++]);
		}
	}
}

char	**filter_tokens(char **tokens)
{
	t_token_processing	tp;

	tp.tokens = tokens;
	tp.filtered_tokens = allocate_filtered_tokens(tokens);
	tp.ignored_tokens = allocate_ignored_tokens(tokens);
	if (!tp.filtered_tokens || !tp.ignored_tokens)
		return (NULL);
	tp.i = 0;
	tp.j = 0;
	tp.k = 0;
	tp.last_redirection = NULL;
	tp.last_target = NULL;
	process_tokens(&tp);
	add_last_redirection(&tp);
	tp.filtered_tokens[tp.j] = NULL;
	tp.ignored_tokens[tp.k] = NULL;
	create_files_from_ignored_tokens(tp.ignored_tokens);
	free_args(tp.ignored_tokens);
	return (tp.filtered_tokens);
}
