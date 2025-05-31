NAME = philo

CC = cc
CFLAGS = -g3 -pthread -Wall -Wextra -Werror

SRCS = \
	srcs/main.c \
	srcs/utils.c \
	srcs/threading.c \
	srcs/init.c \
	srcs/time.c \
	srcs/philo.c \
	srcs/actions.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re