# Nombre del ejecutable
NAME = fractol

# Compilador y flags
CC = cc
# CFLAGS = -Wall -Wextra -Werror

# Directorios de librerías externas
MLX_DIR = ./minilibx_macos
LIBFT_DIR = ./libft

# Flags de MiniLibX y libft
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

# Archivos fuente
SRCS = main.c init.c errors.c render.c utils.c events.c

# Objetos
OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(NAME)

# Compilar el ejecutable
$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

# Regla para compilar archivos .c en .o
%.o: %.c fractol.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

# Limpiar todo
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Recompilar desde cero
re: fclean all

# Evitar errores con nombres estándar
.PHONY: all clean fclean re
