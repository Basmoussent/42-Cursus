/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/02 21:55:58 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/03 14:46:21 by bdenfir		  ###   ########.fr	   */
/*																			*/
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

char	*find_executable(char *cmd, char **envp);
void	error_exit(char *str, int status);
void	free_args(char **args);
int		get_next_line(char **line);
void	ft_norme(char **args, char *cmd, int status);
void	process_cmds(int argc, char **argv, char **envp, int start);
int		open_file(char *filename, int flags, int mode);
void	child_process(char *argv, char **envp, int pipe_in, int pipe_out);
void	here_doc(char *limiter, int argc);
void	handle_here_doc(int *fd, char *limiter);

#endif
