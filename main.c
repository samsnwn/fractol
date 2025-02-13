/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:12:23 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/13 13:23:56 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			app.view.julia_real = parse_double(argv[2]);
			app.view.julia_imag = parse_double(argv[3]);
		}
		render_fractal(&app);
		mlx_loop(app.mlx);
	}
	else
		print_usage();
	return (0);
}
