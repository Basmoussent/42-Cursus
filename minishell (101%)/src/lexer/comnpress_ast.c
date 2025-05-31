/* ************************************************************************** */
/*                                      */
/*                            :::     ::::::::   */
/*   comnpress_ast.c                                    :+:   :+:    :+:   */
/*                          +:+ +:+       +:+    */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+     */
/*   Created: 2025/01/23 19:50:10 by bdenfir           #+#  #+#          */
/*   Updated: 2025/01/24 15:54:23 by bdenfir          ###   ########.fr    */
/*                                      */
/* ************************************************************************** */

#include "minishell.h"

char	*concat_with_space(char *str1, char *str2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = malloc(len1 + len2 + 2);
	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	ft_strcpy(result, str1);
	result[len1] = ' ';
	ft_strcpy(result + len1 + 1, str2);
	return (result);
}

void	split_command_arg(t_ast_node *node)
{
	char	*arg;
	char	*space;

	space = ft_strchr(node->value, ' ');
	if (!space)
		return ;
	arg = ft_strdup(space + 1);
	*space = '\0';
	if (arg)
	{
		node->right = create_ast_node(0, arg);
		free(arg);
	}
}

void	split_ast(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->type == 0)
		return (split_command_arg(node));
	split_ast(node->left);
	split_ast(node->right);
}

void	compress_ast(t_ast_node *node)
{
	char		*new_value;
	t_ast_node	*temp;

	if (!node)
		return ;
	compress_ast(node->left);
	compress_ast(node->right);
	if (node->type == 0 && node->right && node->right->type == 0)
	{
		new_value = concat_with_space(node->value, node->right->value);
		free(node->value);
		node->value = new_value;
		temp = node->right;
		node->right = temp->right;
		free(temp->value);
		free(temp);
	}
}

void	free_ast_node(t_ast_node *node)
{
	if (!node)
		return ;
	free(node->value);
	free(node);
}
