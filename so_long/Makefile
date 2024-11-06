CC = gcc
CFLAGS = -Werror
INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
SRC_DIR = srcs

MLX_LIB = mlx/libmlx.a

SRC_FILES = $(SRC_DIR)/main.c
OBJ_FILES = $(SRC_DIR)/main.o

NAME = so_long

.PHONY: all clean fclean re

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ)  -o $(NAME) $(OBJ_FILES) $(MLX_FLAGS)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm $(NAME)

norme:
	rm -f $(OBJ_FILES) $(NAME)
	norminette $(SRC_FILES) $(H_FILES)

update:
	git add .
	git commit
	git push

re: fclean all
