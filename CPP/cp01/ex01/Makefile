SRC = Zombie.cpp Zombie.hpp zombieHorde.cpp main.cpp
NAME = zombieHorde
CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(SRC) -o $(NAME)

clean:
		rm -rf $(NAME)

fclean: clean

re: fclean all