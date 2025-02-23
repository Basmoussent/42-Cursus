# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME = ../so_long

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fPIE

SRCDIR = srcs
INCDIR = ./include
LIBFTDIR = ../libft
MLXDIR = ../mlx
OBJDIR = objs

SRCS =	$(SRCDIR)/parsing.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/render.c \
		$(SRCDIR)/dfs.c \
		$(SRCDIR)/main.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a
LIBS = -L$(LIBFTDIR) -lft -L$(MLXDIR) -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

INCLUDES = -I $(INCDIR) -I $(LIBFTDIR) -I $(MLXDIR) -I/usr/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -I include -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	$(RM) -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
