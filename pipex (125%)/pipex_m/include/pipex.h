/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:55:58 by bdenfir           #+#    #+#             */
/*   Updated: 2024/12/03 13:36:38 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct t_pipex
{
	int	infile;
	int	outfile;
	int	pipe_fd[2];
	int	current_cmd;

}				t_pipex;

void	parse_commande(char **argv);
char	*find_executable(char *cmd, char **envp);
pid_t	fork_child(t_pipex *data, char **argv, char **envp, int nb_cmd);
void	pipe_redirection(int nb_cmd, t_pipex *data);
void	create_pipe(t_pipex *data);
void	error_exit(char *str, t_pipex *data);
void	clean_data(t_pipex *data);
void	wait_pid(pid_t pid1, pid_t pid2);
void	free_args(char **args);
void	pipe_redirection(int nb_cmd, t_pipex *data);
void	create_pipe(t_pipex *data);
void	execute_child(t_pipex *data, char *cmd, char **args, char **envp);

#endif
