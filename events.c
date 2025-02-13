/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:10:35 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/13 13:23:40 by samcasti         ###   ########.fr       */
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

	move_speed = 0.1 * app->view.scale;
	if (key == KEY_ESC)
		return (on_close(app));
	else if (key == KEY_LEFT)
		app->view.x -= move_speed;
	else if (key == KEY_RIGHT)
		app->view.x += move_speed;
	else if (key == KEY_UP)
		app->view.y -= move_speed;
	else if (key == KEY_DOWN)
		app->view.y += move_speed;
	else if (key == KEY_PLUS)
		app->view.max_iter += 10;
	else if (key == KEY_MINUS && app->view.max_iter > 10)
		app->view.max_iter -= 10;
	render_fractal(app);
	return (0);
}

int	on_mouse_scroll(int button, int x, int y, t_app *app)
{
	const double	zoom_factor = 1.1;

	(void)x;
	(void)y;
	if (button == Button4)
		app->view.scale *= 1.0 / zoom_factor;
	else if (button == Button5)
		app->view.scale *= zoom_factor;
	render_fractal(app);
	return (0);
}
