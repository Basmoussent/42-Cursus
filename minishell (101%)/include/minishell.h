/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:40:52 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 11:11:20 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <signal.h>
# include <sys/ioctl.h>

# define COLOR_RESET   "\033[0m"
# define COLOR_GREEN   "\033[32m"
# define COLOR_RED     "\033[31m"
# define COLOR_YELLOW  "\033[33m"
# define COLOR_CYAN    "\033[36m"
# define COLOR_CYAN_BOLD "\033[1;36m"
# define COLOR_YELLOW_BOLD  "\033[1;33m"
# define TYPE_COLOR "\033[1;34m"
# define VALUE_COLOR "\033[1;32m"
# define INDENT_COLOR "\033[0;33m"

# define HERE_DOC_TMP ".heredoc_tmp"
# define BLANK_FILE ".blank_tmp"

extern volatile int	g_signal_received;

enum
{
	KO = 1,
	OK = 0
};

enum	e_token {
	NONE = 0,
	PIPE = 1,
	TRUNCATE = 2,
	APPEND = 3,
	REDIRECT_INPUT = 4,
	HEREDOC = 5
};

typedef struct s_ast_node
{
	enum e_token		type;
	char				*value;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;

typedef struct s_token_processing
{
	char	**tokens;
	char	**filtered_tokens;
	char	**ignored_tokens;
	int		i;
	int		j;
	int		k;
	char	*last_redirection;
	char	*last_target;
}	t_token_processing;

typedef struct s_data
{
	char		**envp;
	char		**export;
	int			ast;
	char		*hd_file;
	t_ast_node	*current_ast;
	char		**tokens;
	char		*input;
	int			status;
	int			saved_stdin;
	int			saved_stdout;
	int			original_stdin;
	int			original_stdout;
	int			in_shell;
}	t_data;

// Builtins
int			ft_echo(char *str);
int			ft_pwd(t_data *data);
int			ft_env(char **envp, char *arg);
int			ft_exit(char *input, t_data *data);
int			ft_unset(char *input, t_data *data);
int			ft_export(char *str, t_data *data);
int			ft_cd(char *path, t_data *data);
int			ft_ast(t_data *data);

// ENV
int			is_valid_varname(char *var);
void		ft_process_input(char *input, char *buffer);
char		**copy_envp(char **envp);
int			ft_set_env(char *var, char *value, t_data *data);
char		**copy_export_list(char **envp);
char		*get_current_pwd(t_data *data);
int			is_in_export_list(char *var, char **export_list);

// LEXER
int			is_space(char c);
char		*is_quote(char *end);
size_t		ft_strnlen(const char *s, size_t maxlen);
char		*ft_strndup(const char *s, size_t n);
char		**free_tokens(char **tokens);
void		free_args(char **args);
char		**split_whitespace(char *input);
int			count_tokens(char *input);
t_ast_node	*lexing(char *input, t_data *data);
char		*trim_input(char *input);
char		*get_next_quote(char *input, int double_qte);
t_ast_node	*parse_tokens(char **tokens, t_data *data);
t_ast_node	*create_ast_node(enum e_token type, char *value);
char		*expand_all_variables(char *input, t_data *data);
char		*get_env_value(char *name, t_data *data);
void		free_ast(t_ast_node *node);
void		compress_ast(t_ast_node *node);
void		split_ast(t_ast_node *node);
void		clean_redirections(t_ast_node *node);
char		**filter_tokens(char **tokens);
int			is_speci(char *token);
int			count_tokens_array(char **tokens);
char		**allocate_filtered_tokens(char **tokens);
void		skip_whitespace(char **start);
char		**allocate_tokens(char *input);
char		*find_token_end(char *start);
int			is_special_char(char *input);
char		**allocate_ignored_tokens(char **tokens);
void		handle_double_quote(bool *in_quotes, size_t *i);
void		skip_single_quotes(char *result, size_t *i);
char		*handle_expansion(char *result, t_data *data, size_t *i);
char		*process_variables(char *result, t_data *data);
char		*expand_single_variable(char *input, t_data *data);
void		print_ast(t_ast_node *node, char *prefix, int is_left);
char		*expand_pid(t_data *data);
char		**fix_order(char **tokens);
char		*join_expand_pid(char *pid, char *str);
char		*join_expanded_status(int status, char *input, char *str);
char		*join_expanded_pid(char *pid, char *input, char *str);
int			find_first_dollar(char *input);
char		*ft_strdup_without_dollar(char *input, char *start);
int			found_builtin(char *input);

// EXEC
int			heredoc_logic(char *delimiter, t_data *data);
void		exec_ast(t_ast_node *node, t_data *data);
void		reset_stream(int saved_stdin, int saved_stdout);
int			handle_redirection(t_ast_node *node, t_data *data);
int			exec_builtin(t_ast_node *node, t_data *data);
int			is_builtin(t_ast_node *node);
void		redirect_output(t_ast_node *node, int fd);

// UTILS
bool		validate_command(const char *cmd);
void		cleanup_and_exit(t_ast_node *root, t_data *data,
				char **args, char *cmd_path);
void		handle_signals(int signum);
void		handle_signals_child(void);
void		handle_sigint_child(int signum);
void		cleanup_shell(t_data *data);
void		close_fds(t_data *data);
char		*remove_quotes(char *input);
int			can_expand(char *rslt);
char		*expand_status(int status, char *input);

// Export utils
int			add_to_export(char *var, t_data *data);
void		print_export_list(char **export_list);
char		**copy_export_list(char **envp);
int			print_export_error(int error, char *arg);
char		*join_var_value(char *var, char *value);

// Env utils
int			add_new_var_to_env(char *full_entry, t_data *data);
int			ft_set_env(char *var, char *value, t_data *data);
char		**copy_existing_env(char **envp);

// Exec utils
void		handle_error(const char *msg, int status);
void		handle_command_child(t_ast_node *node, t_data *data, char **args);
void		handle_command_parent(pid_t pid, char **args);
char		**prepare_args(t_ast_node *node);
void		get_cmd_path(t_ast_node *node, char **envp,
				char **cmd_path, char **args);
char		*find_executable(char *cmd, char **envp);

// Pipe utils
void		execute_child(t_ast_node *node, t_data *data, int *pipe_fds);
void		handle_right_child(t_ast_node *node, t_data *data, int *pipe_fds);
void		handle_pipe_parent(int *pipe_fds,
				pid_t left_pid, pid_t right_pid);

// Redirect utils
void		redirect_output(t_ast_node *node, int fd);
void		reset_stream(int saved_stdin, int saved_stdout);
int			open_redirection_file(t_ast_node *node, t_data *data);
int			can_write_to_file(char *filepath);

// Heredoc utils
void		process_heredoc_line(char *line, int fd, t_data *data, int expand);
int			handle_heredoc_input(int fd, char *delimiter, t_data *data,
				int should_expand);

// Shell utils
char		*read_input(void);
void		process_input(t_data *data);
void		cleanup_current_iteration(t_data *data);
void		shell_loop(t_data *data);

// Cleanup utils
void		cleanup_data_strings(t_data *data);
void		cleanup_data_arrays(t_data *data);

#endif