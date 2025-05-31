/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cd.c											   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/20 14:49:39 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/01/20 15:02:05 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

// Function to print error messages
static	void	print_cd_error(int code)
{
	if (code == 1)
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
	else if (code == 2)
		ft_putstr_fd("cd: no such file or directory\n", STDERR_FILENO);
}

char	*get_current_pwd(t_data *data)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_strdup(get_env_value("PWD", data));
	return (pwd);
}

static int	update_pwd(char *old_pwd, t_data *data)
{
	char	*new_pwd;
	int		ret;

	new_pwd = get_current_pwd(data);
	if (!new_pwd)
		return (KO);
	if (ft_set_env("PWD", new_pwd, data) != OK)
	{
		free(new_pwd);
		return (KO);
	}
	ret = ft_set_env("OLDPWD", old_pwd, data);
	free(new_pwd);
	if (ret != OK)
		return (KO);
	return (OK);
}

int	ft_cd(char *path, t_data *data)
{
	char	*old_pwd;
	int		ret;

	old_pwd = get_current_pwd(data);
	if (!old_pwd)
		return (print_cd_error(3), KO);
	if (!path || chdir(path) == -1)
	{
		free(old_pwd);
		return (print_cd_error(2), KO);
	}
	ret = update_pwd(old_pwd, data);
	free(old_pwd);
	return (ret);
}
