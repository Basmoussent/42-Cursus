/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   exit.c			:+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2025/01/14 22:37:39 by bdenfir		   #+#  #+#		  */
/*   Updated: 2025/01/14 22:44:57 by bdenfir		  ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#include "minishell.h"

static int	is_number(char *str)
{
	int	single_q;
	int	double_q;
	int	plus_minus_count;

	single_q = 0;
	double_q = 0;
	plus_minus_count = 0;
	while (*str)
	{
		if (*str == '"' && double_q == 0)
			double_q++;
		else if (*str == '"' && double_q != 0)
			double_q--;
		else if (*str == '\'' && single_q == 0)
			single_q++;
		else if (*str == '\'' && single_q != 0)
			single_q--;
		else if ((*str == '+' || *str == '-'))
			plus_minus_count++;
		else if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (double_q == 0 && single_q == 0 && plus_minus_count < 2);
}

static void	print_error(char *msg, char *arg)
{
	write(STDERR_FILENO, "exit\n", 5);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (arg)
	{
		write(STDERR_FILENO, arg, ft_strlen(arg));
		write(STDERR_FILENO, ": ", 2);
	}
	write(STDERR_FILENO, "\n", 1);
}

int	is_within_long_long_range(const char *str)
{
	int			len;
	const char	*limit;

	limit = "9223372036854775807";
	if (str[0] == '-')
		limit = "9223372036854775808";
	str = str +(str[0] == '-');
	len = 0;
	while (str[len])
		len++;
	if (len > 19)
		return (0);
	if (len < 19)
		return (1);
	while (*str++ && *limit++)
	{
		if (*str > *limit)
			return (0);
		if (*str < *limit)
			return (1);
	}
	return (1);
}

static int	handle_exit_error(char *arg)
{
	if (!is_within_long_long_range(arg) || !is_number(arg))
	{
		write(STDERR_FILENO, "minishell: exit: ", 17);
		write(STDERR_FILENO, arg, ft_strlen(arg));
		write(STDERR_FILENO, " numeric argument required\n", 27);
		return (2);
	}
	return (0);
}

int	ft_exit(char *input, t_data *data)
{
	char		*arg;
	long long	exit_status;

	arg = input;
	exit_status = 0;
	write(STDERR_FILENO, "exit\n", 5);
	if (*arg == '\0')
	{
		cleanup_shell(data);
		exit(0);
	}
	if (ft_strchr(arg, ' '))
		return (print_error("minishell: exit: too many arguments", NULL), 1);
	if (handle_exit_error(arg))
	{
		cleanup_shell(data);
		exit(2);
	}
	arg = remove_quotes(arg);
	exit_status = ft_atol(arg);
	if (exit_status < 0)
		exit_status = 256 + exit_status % 256;
	cleanup_shell(data);
	exit(exit_status);
}
