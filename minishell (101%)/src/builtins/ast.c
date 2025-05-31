/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:16:22 by bdenfir           #+#    #+#             */
/*   Updated: 2025/01/22 20:53:33 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ast(t_data *data)
{
	if (!data)
		return (KO);
	if (data->ast == 1)
	{
		printf(COLOR_YELLOW_BOLD "AST is disabled\n" COLOR_RESET);
		data->ast = 0;
	}
	else
	{
		printf(COLOR_YELLOW_BOLD "AST is enabled\n" COLOR_RESET);
		data->ast = 1;
	}
	return (OK);
}
