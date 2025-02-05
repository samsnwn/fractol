/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:10:35 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/05 18:11:45 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_close(t_app *app)
{
	mlx_destroy_image(app->mlx, app->image.ptr);
	mlx_destroy_window(app->mlx, app->window);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(EXIT_SUCCESS);
}

int	on_key_press(int key, t_app *app)
{
	double	move_speed;

	move_speed = 0.1 * app->viewport.scale;
	if (key == KEY_ESC)
		return (on_close(app));
	else if (key == KEY_LEFT)
		app->viewport.center_x -= move_speed;
	else if (key == KEY_RIGHT)
		app->viewport.center_x += move_speed;
	else if (key == KEY_UP)
		app->viewport.center_y -= move_speed;
	else if (key == KEY_DOWN)
		app->viewport.center_y += move_speed;
	else if (key == KEY_PLUS)
		app->viewport.max_iter += 10;
	else if (key == KEY_MINUS && app->viewport.max_iter > 10)
		app->viewport.max_iter -= 10;
	render_fractal(app);
	return (0);
}

int	on_mouse_scroll(int button, int x, int y, t_app *app)
{
	const double	zoom_factor = 1.1;

	(void)x;
	(void)y;
	if (button == Button4)
		app->viewport.scale *= 1.0 / zoom_factor;
	else if (button == Button5)
		app->viewport.scale *= zoom_factor;
	render_fractal(app);
	return (0);
}

int	on_mouse_move(int x, int y, t_app *app)
{
	t_range	screen;
	t_range	fractal;

	if (!ft_strcmp(app->fractal_type, "julia"))
	{
		screen = (t_range){0, WINDOW_WIDTH};
		fractal = (t_range){-2, 2};
		app->viewport.julia_real = map_range(normalize(x, screen), fractal);

		screen = (t_range){0, WINDOW_HEIGHT};
		app->viewport.julia_imag = map_range(normalize(y, screen), fractal);
		
		render_fractal(app);
	}
	return (0);
}
