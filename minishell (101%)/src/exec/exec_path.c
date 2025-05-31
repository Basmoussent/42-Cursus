/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:45:47 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 09:19:04 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redirection(t_ast_node *node, t_data *data)
{
	int	fd;

	if (!node)
		return (-1);
	fd = open_redirection_file(node, data);
	if (fd == -1)
		return (perror("Error opening file"), g_signal_received = 1, -1);
	if (node->type == REDIRECT_INPUT || node->type == HEREDOC)
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

// Function to check if a cmd is a builtin
int	is_builtin(t_ast_node *node)
{
	if (!node || !node->value)
		return (0);
	if (ft_strncmp(node->value, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(node->value, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(node->value, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(node->value, "export", 7) == 0)
		return (1);
	if (ft_strncmp(node->value, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(node->value, "exit", 5) == 0)
		return (1);
	if (ft_strncmp(node->value, "env", 4) == 0)
		return (1);
	return (0);
}

// Function to execute a builtin command
int	exec_builtin(t_ast_node *node, t_data *data)
{
	char	*arg;

	if (!node || !node->value)
		return (0);
	arg = "";
	if (node->right && node->right->value)
		arg = node->right->value;
	if (ft_strncmp(node->value, "echo", 5) == 0)
		return (ft_echo(arg));
	if (ft_strncmp(node->value, "cd", 3) == 0)
		return (ft_cd(arg, data));
	if (ft_strncmp(node->value, "pwd", 4) == 0)
		return (ft_pwd(data));
	if (ft_strncmp(node->value, "export", 7) == 0)
		return (ft_export(arg, data));
	if (ft_strncmp(node->value, "unset", 6) == 0)
		return (ft_unset(arg, data));
	if (ft_strncmp(node->value, "exit", 5) == 0)
		return (ft_exit(arg, data));
	if (ft_strncmp(node->value, "env", 4) == 0)
		return (ft_env(data->envp, arg));
	return (0);
}

void
	get_cmd_path(t_ast_node *node, char **envp, char **cmd_path, char **args)
{
	if (!envp || !envp[0])
		return ;
	if (access(node->value, X_OK) == 0)
		*cmd_path = ft_strdup(node->value);
	else
		*cmd_path = find_executable(node->value, envp);
	if (!*cmd_path)
	{
		free_args(args);
		handle_error("Command not found", 127);
	}
}

void	cleanup_and_exit(t_ast_node *root, t_data *data
, char **args, char *cmd_path)
{
	if (root)
		free_ast(root);
	if (data->envp)
		free_args(data->envp);
	if (args)
		free_args(args);
	if (cmd_path)
		free(cmd_path);
	exit(1);
}
