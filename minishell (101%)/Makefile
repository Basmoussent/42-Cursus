# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: 42student <42student@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 12:00:00 by 42student        #+#    #+#              #
#    Updated: 2024/02/17 12:00:00 by 42student       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = -I include -I $(LIBFT_DIR)

BUILD_DIR = build

SRCS = src/main.c \
       src/builtins/ast.c src/builtins/cd.c src/builtins/echo.c src/builtins/env.c \
       src/builtins/exit.c src/builtins/export.c src/builtins/pwd.c src/builtins/unset.c \
       src/exec/exec.c src/exec/exec_path.c src/exec/exec_utils.c src/exec/pipe_utils.c src/exec/redirect_utils.c \
       src/lexer/additional_utils.c src/lexer/comnpress_ast.c src/lexer/create_ast.c src/lexer/expanding.c \
       src/lexer/fix_tokens.c src/lexer/input_reading.c src/lexer/lexer_utils.c src/lexer/lexing.c \
       src/lexer/trim_and_count.c src/lexer/utils_tokens.c \
       src/utils/cleanup_utils.c src/utils/env_utils.c src/utils/exec.c src/utils/export_utils.c \
       src/utils/shell_loop.c src/utils/shell_utils.c src/utils/signal.c src/utils/string.c src/utils/additional_utils.c \
	   src/utils/expander.c src/lexer/print_ast.c src/lexer/more_utils.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR) $(dir $(OBJS))

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(INCLUDE) -lreadline
	@echo "\n\033[0;32mDone !"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(BUILD_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
