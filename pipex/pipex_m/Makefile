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

#ERROR CASES
EXPECTED_OUTPUT1 = "No such file or directory"
EXPECTED_OUTPUT2 = "Succes
EXPECTED_OUTPUT3 = "Bad address"


#BASIC TEST
TEST1 = ./$(NAME) "Makefile" "cat" "rev" "../test/out/out_rev"
TEST2 = ./$(NAME) "../test/input.txt" "grep pattern" "wc -l" "../test/out/out_grep_wc"
TEST3 = ./$(NAME) "../test/input.txt" "cat" "head -n 1" "../test/out/out_head"

#TRICKY TESTS
TRICKY_TEST1 = ./$(NAME)
TRICKY_TEST2 = ./$(NAME) "nonexistent.txt" "cat" "rev" "../test/out/out_fail"
TRICKY_TEST3 = ./$(NAME) "Makefile" "" "rev" "../test/out/out_empty_cmd"
TRICKY_TEST4 = ./$(NAME) "Makefile" "cat" "" "../test/out/out_empty_cmd2"
TRICKY_TEST5 = ./$(NAME) "Makefile" "invalidcommand" "cat" "../test/out/out_fail_cmd" 
TRICKY_TEST6 = ./$(NAME) "Makefile" "cat" "invalidcommand" "../test/out/out_fail_cmd2"
TRICKY_TEST7 = ./$(NAME) "Makefile" "sleep 10" "rev" "../test/out/out_timeout"
TRICKY_TEST8 = ./$(NAME)
TRICKY_TEST9 = ./$(NAME) "Makefile"
TRICKY_TEST10 = ./$(NAME) "Makefile" "cat"
TRICKY_TEST11 = ./$(NAME) "Makefile" "cat" "wc -w"
TRICKY_TEST12 = ./$(NAME) "Makefile" "cat" "wc -w" "../test/out/Working!"
TRICKY_TEST13 = ./$(NAME) "Makefile" "cat" "wc -w" "../test/out/is_it_really?" ""

# Colors
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
RESET = \033[0m


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
	rm -f input.txt out_rev out_grep_wc out_head
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

test: all
	@mkdir -p ../test/out/
	@echo "$(YELLOW)Running Test 1...$(RESET)"
	@$(TEST1) && echo "$(GREEN)Test 1: File out_rev created successfully.$(RESET)" || echo "$(RED)Test 1 Failed!$(RESET)"
	@echo "--------------------------------------"

	@echo "$(YELLOW)Running Test 2...$(RESET)"
	@$(TEST2) && echo "$(GREEN)Test 2: File out_grep_wc created successfully.$(RESET)" || echo "$(RED)Test 2 Failed!$(RESET)"
	@echo "--------------------------------------"

	@echo "$(YELLOW)Running Test 3...$(RESET)"
	@$(TEST3) && echo "$(GREEN)Test 3: File out_sorted created successfully.$(RESET)" || echo "$(RED)Test 3 Failed!$(RESET)"
	@echo "--------------------------------------"

tricky: all
	@mkdir -p ../test/out/
	@echo "$(YELLOW)Running Tricky Tests...$(RESET)"

	@echo "$(YELLOW)Test 1: Empty input file$(RESET)"
	@output=$$($(TRICKY_TEST1) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 1: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 1: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 1: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 1: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 2: Nonexistent input file$(RESET)"
	@output=$$($(TRICKY_TEST2) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 2: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 2: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 2: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 2: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 3: Empty cmd1$(RESET)"
	@output=$$($(TRICKY_TEST3) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 3: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 3: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 3: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 3: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 4: Empty cmd2$(RESET)"
	@output=$$($(TRICKY_TEST4) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 4: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 4: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 4: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 4: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 5: Invalid cmd1$(RESET)"
	@output=$$($(TRICKY_TEST5) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 5: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 5: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 5: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 5: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 6: Invalid cmd2$(RESET)"
	@output=$$($(TRICKY_TEST6) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 6: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 6: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 6: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 6: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 7: Slow command execution$(RESET)"
	@output=$$($(TRICKY_TEST7) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 7: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 7: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 7: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 7: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 8: No arguments$(RESET)"
	@output=$$($(TRICKY_TEST8) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 8: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 8: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 8: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 8: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 9: Only input file$(RESET)"
	@output=$$($(TRICKY_TEST9) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 9: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 9: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 9: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 9: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 10: Input file and one command$(RESET)"
	@output=$$($(TRICKY_TEST10) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 10: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 10: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 10: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 10: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 11: Valid pipeline but no output file$(RESET)"
	@output=$$($(TRICKY_TEST11) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 11: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 11: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 11: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 11: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 12: Valid pipeline with valid output file$(RESET)"
	@$(TRICKY_TEST12) && echo "$(GREEN)Test 12: Passed.$(RESET)" || echo "$(RED)Test 12: Failed!$(RESET)"
	@echo "--------------------------------------"

	@echo "$(YELLOW)Test 13: Valid pipeline with missing final argument$(RESET)"
	@output=$$($(TRICKY_TEST13) 2>&1); \
	echo "$$output"; \
	case "$$output" in \
		*$(expected_output1)*) \
			echo "$(GREEN)Test 13: Passed.$(RESET)"; \
			;; \
		*$(expected_output2)*) \
			echo "$(GREEN)Test 13: Passed.$(RESET)"; \
			;; \
		*$(expected_output3)*) \
			echo "$(GREEN)Test 13: Passed.$(RESET)"; \
			;; \
		*) \
			echo "$(RED)Test 13: Failed!$(RESET)"; \
			;; \
	esac
	@echo "--------------------------------------"

	@echo "$(GREEN)Tricky Tests Completed.$(RESET)"

re: fclean all
