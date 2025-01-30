#include "fractol.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage:\n", STDERR_FILENO);
	ft_putstr_fd("  ./fractol mandelbrot\n", STDERR_FILENO);
	ft_putstr_fd("  ./fractol julia <real> <imaginary>\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void  free_exit(void *mlx, char *message)
{
  perror(message);
  free(mlx);
  exit(EXIT_FAILURE);
}