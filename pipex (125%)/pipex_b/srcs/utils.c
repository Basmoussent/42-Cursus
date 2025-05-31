/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/03 14:45:01 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/10/05 21:42:34 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *str, int status)
{
	ft_putstr_fd(str, 2);
	perror("\nerrno");
	exit(status);
}

void	ft_norme(char **args, char *cmd, int status)
{
	if (args && *args)
		free_args(args);
	if (cmd != NULL)
		free(cmd);
	exit(status);
}

void	handle_here_doc(int *fd, char *l)
{
	char	*l1;

	close(fd[0]);
	while (get_next_line(&l1) > 0)
	{
		if (ft_strncmp(l1, l, ft_strlen(l)) == 0 && l1[ft_strlen(l)] == '\n')
		{
			free(l1);
			close(fd[1]);
			exit(EXIT_SUCCESS);
		}
		write(fd[1], l1, ft_strlen(l1));
		write(fd[1], "\n", 1);
		free(l1);
	}
	close(fd[1]);
	free(l1);
	exit(EXIT_FAILURE);
}
