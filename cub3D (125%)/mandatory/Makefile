# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME = ../cub3d

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fPIE

SRCDIR = srcs
EXECDIR = $(SRCDIR)/exec
PARDIR = $(SRCDIR)/parsing
MOVDIR = $(SRCDIR)/movement
UTILDIR = $(SRCDIR)/utils

INCDIR = ./include
LIBFTDIR = ../libft
MLXDIR = ../mlx
OBJDIR = build

SRCS = $(SRCDIR)/main.c \
       $(PARDIR)/parsing.c $(PARDIR)/map.c $(PARDIR)/texture.c $(PARDIR)/player.c \
       $(EXECDIR)/exec.c $(EXECDIR)/get_rayon_data.c $(EXECDIR)/graphical.c \
       $(EXECDIR)/get_color.c $(EXECDIR)/door_system.c $(EXECDIR)/init_doors.c $(EXECDIR)/sun.c \
       $(MOVDIR)/key_controls.c $(MOVDIR)/move_player.c $(MOVDIR)/rotate_camera.c \
       $(UTILDIR)/free.c $(UTILDIR)/free_graphical.c $(UTILDIR)/utils.c $(UTILDIR)/map.c \
	   $(UTILDIR)/init_minimap.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a
LIBS = -L$(LIBFTDIR) -lft -L$(MLXDIR) -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

INCLUDES = -I $(INCDIR) -I $(LIBFTDIR) -I $(MLXDIR) -I/usr/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -I include -o $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR) $(OBJDIR)/$(SRCDIR) $(OBJDIR)/$(EXECDIR) $(OBJDIR)/$(PARDIR) $(OBJDIR)/$(MOVDIR) $(OBJDIR)/$(UTILDIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	$(RM) -r $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

norme:
	@norminette $(LIBFTDIR)
	@norminette $(SRCS)

re: fclean all

.PHONY: all clean fclean re
