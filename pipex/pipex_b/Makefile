CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I include

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_DIR = srcs
OBJ_DIR = obj

H_FILES = libft/libft.h \
		 include/pipex.h \

SRC_FILES = $(SRC_DIR)/pipex.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/utils2.o \

OBJ_FILES = $(OBJ_DIR)/pipex.o\
			$(OBJ_DIR)/utils.o \
			$(OBJ_DIR)/utils2.o \

LIBFT_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memmove.c\
	ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_split.c\
	ft_strtrim.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME = pipex

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT_LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT_LIB)

norme:
	rm -f $(OBJ_FILES) $(NAME)
	norminette $(SRC_FILES) $(H_FILES)
	@cd $(LIBFT_DIR) && norminette

update:
	git add .
	git commit
	git push

re: fclean all
