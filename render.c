/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:14:27 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/13 13:24:07 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_image *image, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	offset = (y * image->length) + (x * (image->bpp / 8));
	*(unsigned int *)(image->buffer + offset) = color;
}

static int	calculate_color(int iterations, int max_iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iterations / max_iterations;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static int	get_iterations(t_complex c, t_view *view, char *type)
{
	t_complex	z;
	t_complex	julia;
	int			i;
	double		x_temp;

	z = (t_complex){0, 0};
	julia = (t_complex){view->julia_real, view->julia_imag};
	i = 0;
	if (!ft_strcmp(type, "julia"))
	{
		z = c;
		c = julia;
	}
	while (i < view->max_iter)
	{
		x_temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = x_temp;
		if (z.real * z.real + z.imag * z.imag > 4.0)
			return (i);
		i++;
	}
	return (view->max_iter);
}

void	render_fractal(t_app *app)
{
	int			y;
	int			x;
	t_complex	c;
	int			iterations;
	int			color;
	t_range		screen;
	t_range		fractal;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			screen = (t_range){0, WINDOW_WIDTH};
			fractal = (t_range){-2 * app->view.scale, 2 * app->view.scale};
			c.real = map_range(normalize(x, screen), fractal) + app->view.x;
			screen = (t_range){0, WINDOW_HEIGHT};
			c.imag = map_range(normalize(y, screen), fractal) + app->view.y;
			iterations = get_iterations(c, &app->view, app->fractal_type);
			color = calculate_color(iterations, app->view.max_iter);
			put_pixel(&app->image, x, y, color);
		}
	}
	mlx_put_image_to_window(app->mlx, app->window, app->image.ptr, 0, 0);
}
