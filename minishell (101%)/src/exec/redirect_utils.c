/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:45:47 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 10:36:24 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_output(t_ast_node *node, int fd)
{
	if (node->type == REDIRECT_INPUT || node->type == HEREDOC)
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	reset_stream(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
}

int	open_redirection_file(t_ast_node *node, t_data *data)
{
	if (!node->right || !node->right->value)
		return (printf("Syntax error near unexpected token %s\n", node->value),
			g_signal_received = 2, -1);
	if (access(node->right->value, F_OK) == 0)
		if (!can_write_to_file(node->right->value))
			return (-1);
	if (node->type == TRUNCATE)
		return (open(node->right->value, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	if (node->type == APPEND)
		return (open(node->right->value, O_WRONLY | O_CREAT | O_APPEND, 0644));
	if (node->type == REDIRECT_INPUT)
		return (open(node->right->value, O_RDONLY));
	if (node->type == HEREDOC)
		return (heredoc_logic(node->right->value, data));
	return (-1);
}

int	can_write_to_file(char *filepath)
{
	int		fd;
	ssize_t	ret;

	fd = open(filepath, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (0);
	ret = write(fd, "", 0);
	if (ret == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
