NAME = bureaucrat

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp \

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) Garden_shrubbery

fclean: clean
	rm -f $(NAME) Garden_shrubbery

re: fclean all

.PHONY: all clean fclean re
