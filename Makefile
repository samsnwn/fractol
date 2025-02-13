NAME = fractol

CC = cc

MLX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft

MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c init.c errors.c render.c utils.c events.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
