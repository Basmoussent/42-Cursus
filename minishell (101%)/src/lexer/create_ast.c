/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   create_ast.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/17 18:52:21 by amine			 #+#	#+#			 */
/*   Updated: 2025/01/24 16:02:07 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int	is_type(enum e_token type)
{
	return (type == PIPE || type == TRUNCATE || type == APPEND
		|| type == REDIRECT_INPUT || type == HEREDOC);
}

enum	e_token	classify_token(char *token)
{
	if (ft_strncmp(token, ">>", 2) == 0)
		return (APPEND);
	else if (ft_strncmp(token, "<<", 2) == 0)
		return (HEREDOC);
	else if (ft_strncmp(token, "|", 1) == 0)
		return (PIPE);
	else if (ft_strncmp(token, ">", 1) == 0)
		return (TRUNCATE);
	else if (ft_strncmp(token, "<", 1) == 0)
		return (REDIRECT_INPUT);
	return (NONE);
}

t_ast_node	*create_ast_node(enum e_token type, char *value)
{
	t_ast_node	*node;

	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	node->type = type;
	node->value = ft_strdup(value);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_ast_node	*loop_node(t_ast_node *root, t_ast_node **current, char *token)
{
	t_ast_node		*node;

	node = create_ast_node(classify_token(token), token);
	if (!node)
		return (NULL);
	if (!root)
	{
		root = node;
		*current = node;
	}
	else
	{
		if (is_type(node->type))
		{
			node->left = root;
			root = node;
			*current = node;
		}
		else
		{
			(*current)->right = node;
			*current = node;
		}
	}
	return (root);
}

t_ast_node	*parse_tokens(char **tokens, t_data *data)
{
	t_ast_node	*root;
	t_ast_node	*current;
	char		*expanded_token;
	int			i;

	root = NULL;
	current = NULL;
	i = 0;
	while (tokens[i])
	{
		expanded_token = expand_all_variables(tokens[i], data);
		root = loop_node(root, &current, expanded_token);
		free(expanded_token);
		if (!root)
			return (NULL);
		i++;
	}
	compress_ast(root);
	split_ast(root);
	return (root);
}
