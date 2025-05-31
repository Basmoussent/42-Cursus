.PHONY: all bonus clean fclean re pipex_m pipex_b norme

DIR_M := mandatory
DIR_B := bonus
DIR_MLX := mlx

# Default target
all: pipex_m

# Bonus target
bonus: pipex_b

library:
	@echo "Building in mlx library"
	@$(MAKE) -C $(DIR_MLX)

pipex_m: library
	@echo "Building in so_long..."
	@$(MAKE) -C $(DIR_M)

pipex_b: library
	@echo "Building in so_long..."
	@$(MAKE) -C $(DIR_B)

clean:
	@echo "Cleaning in all directories..."
	@$(MAKE) -C $(DIR_M) clean
	@$(MAKE) -C $(DIR_B) clean

fclean:
	@echo "Fully cleaning in all directories..."
	@$(MAKE) -C $(DIR_M) fclean
	@$(MAKE) -C $(DIR_B) fclean

norme:
	@echo "Norme check for Mandatory folder ..."
	norminette $(DIR_M)/srcs
	norminette $(DIR_M)/include/struct.h
	@echo "Norme check for libft folder ..."
	norminette libft
	@echo "Norme check for bonus folder ..."
	norminette $(DIR_B)/srcs
	norminette $(DIR_B)/include/struct.h

re: fclean all