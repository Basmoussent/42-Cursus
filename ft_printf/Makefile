CC = cc
CFLAGS = -Wall -Wextra -Werror -I include
AR = ar

SRC_DIR = srcs
OBJ_DIR = obj

H_FILES = include/libft.h \
          include/ft_printf.h

SRC_FILES = $(SRC_DIR)/convert.c \
            $(SRC_DIR)/ft_printf.c \
            $(SRC_DIR)/h_numbers.c \
            $(SRC_DIR)/h_string.c \
            $(SRC_DIR)/h_utils.c

OBJ_FILES = $(SRC_DIR)/convert.o \
            $(SRC_DIR)/ft_printf.o \
            $(SRC_DIR)/h_numbers.o \
            $(SRC_DIR)/h_string.o \
            $(SRC_DIR)/h_utils.o

NAME = libftprintf.a

TEST_EXEC = test_ft_printf
TEST_SRC = test/test_main.c


.PHONY: all clean fclean re test norme

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Creating $(NAME)..."
	$(AR) rc $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(H_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	rm -rf $(obj)
	rm -f $(TEST_EXEC)

fclean: clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)

norme:
	@echo "Running norminette..."
	norminette $(SRC_FILES) $(H_FILES)

test: $(NAME) $(TEST_SRC)
	@echo "Compiling test executable..."
	$(CC) $(CFLAGS) -I include $(TEST_SRC) $(NAME) -o $(TEST_EXEC)
	@echo "Running tests..."
	./$(TEST_EXEC)

update:
	@echo "Updating git repository..."
	git add .
	git commit -m "Update project"
	git push

re: fclean all
