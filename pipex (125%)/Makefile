.PHONY: all bonus clean fclean re pipex_m pipex_b

DIR_M := pipex_m
DIR_B := pipex_b

# Default target
all: pipex_m

# Bonus target
bonus: pipex_b

pipex_m:
	@echo "Building in pipex_m..."
	@$(MAKE) -C $(DIR_M)

pipex_b:
	@echo "Building in pipex_b..."
	@$(MAKE) -C $(DIR_B)

clean:
	@echo "Cleaning in all directories..."
	@$(MAKE) -C $(DIR_M) clean
	@$(MAKE) -C $(DIR_B) clean

fclean:
	@echo "Fully cleaning in all directories..."
	@$(MAKE) -C $(DIR_M) fclean
	@$(MAKE) -C $(DIR_B) fclean

re: fclean all
