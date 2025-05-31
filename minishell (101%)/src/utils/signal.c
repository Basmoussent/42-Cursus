/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   signal.c								 :+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2025/01/27 16:25:11 by akassous		#+#  #+#		  */
/*   Updated: 2025/01/29 15:26:41 by bdenfir		  ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signals(int signum)
{
	g_signal_received += signum;
	if (signum == 2)
	{
		g_signal_received = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signum == SIGQUIT)
	{
		write(2, "Quit (core dumped)\n", ft_strlen("Quit (core dumped)\n"));
		exit (1);
	}
}

void	sigquit_handler(int signum)
{
	(void)signum;
}

void	handle_sigint_child(int signum)
{
	g_signal_received += signum;
	if (signum == 2)
	{
		g_signal_received = 130;
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
