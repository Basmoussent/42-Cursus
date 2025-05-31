CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE
NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memmove.c\
	ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_split.c\
	ft_strtrim.c get_next_line_bonus.c ft_occur.c ft_realloc.c ft_skip_it.c ft_atol.c ft_strcpy.c ft_free.c ft_strcmp.c

BONUS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

OBJS = $(SRCS:.c=.o)
BONUS_OBJECTS = $(BONUS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n\033[0;32mCréation de la bibliothèque %s... ✅\033[0m\n" $(NAME)
	@ar rc $(NAME) $(OBJS)
	@echo "\033[0;32mCompliling libft is done !"

%.o: %.c
	@printf "\033[0;33mCompilation en cours... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "\033[0;31mSuppression des fichiers objets...\033[0m\n"
	@rm -rf $(OBJS)
	@rm -rf $(BONUS_OBJECTS)

bonus: $(BONUS_OBJECTS)
	@printf "\n\033[0;36mAjout des fichiers bonus à %s... 🎁\033[0m\n" $(NAME)
	@ar r $(NAME) $^
	@echo "\033[0;32mCompliling libft is done !"

fclean: clean
	@printf "\033[0;31mSuppression de %s...\033[0m\n" $(NAME)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus