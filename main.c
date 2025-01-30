#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_app	app;

	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot")) || (argc == 4
			&& !ft_strcmp(argv[1], "julia")))
	{
		app.fractal_type = argv[1];
		init_app(&app);
		if (!ft_strcmp(argv[1], "julia"))
		{
			app.viewport.julia_real = parse_double(argv[2]);
			app.viewport.julia_imag = parse_double(argv[3]);
		}
		render_fractal(&app);
		mlx_loop(app.mlx);
	}
	else
		print_usage();
	return (0);
}
