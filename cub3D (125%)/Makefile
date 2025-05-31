.PHONY: all bonus clean fclean re cub3d  norme

DIR_M := mandatory
DIR_MLX := mlx

all: cub3d

norme: file_norme

library:
	@echo "Building in mlx library"
	@$(MAKE) -C $(DIR_MLX)

cub3d: library
	@echo "Building in cub3d..."
	@$(MAKE) -C $(DIR_M)

file_norme:
	@$(MAKE) -C $(DIR_M) norme

clean:
	@echo "Cleaning in all directories..."
	@$(MAKE) -C $(DIR_M) clean

fclean:
	@echo "Fully cleaning in all directories..."
	@$(MAKE) -C $(DIR_M) fclean

re: fclean all