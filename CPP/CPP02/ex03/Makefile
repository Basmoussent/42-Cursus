SRC = main.cpp Fixed.cpp bsp.cpp Point.cpp
NAME = Fixed
CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(SRC) -o $(NAME)

clean:
		rm -rf $(NAME)

fclean: clean

re: fclean all