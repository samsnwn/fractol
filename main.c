#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
	  fractol.name = argv[1];
    fractol.julia_x = string_to_double(argv[2]);
    fractol.julia_y = string_to_double(argv[3]);
		start_fractol(&fractol);
		draw_fractol(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		ft_putstr_fd("Incorrect input\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
