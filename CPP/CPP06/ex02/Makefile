NAME = identify_test
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp identify.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp identify.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 