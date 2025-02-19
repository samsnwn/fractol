/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:12:08 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/13 13:23:48 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	setup_viewport(t_view *view)
{
	view->x = 0.0;
	view->y = 0.0;
	view->scale = 1.0;
	view->max_iter = MAX_ITERATIONS;
}

static void	setup_events(t_app *app)
{
	mlx_hook(app->window, KeyPress, KeyPressMask, on_key_press, app);
	mlx_hook(app->window, ButtonPress, ButtonPressMask, on_mouse_scroll, app);
	mlx_hook(app->window, DestroyNotify, StructureNotifyMask, on_close, app);
}

void	init_app(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		exit(EXIT_FAILURE);
	app->window = mlx_new_window(app->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			app->fractal_type);
	if (!app->window)
	{
		mlx_destroy_display(app->mlx);
		free_exit(app->mlx, "Unable to create mlx connection");
	}
	app->image.ptr = mlx_new_image(app->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!app->image.ptr)
	{
		mlx_destroy_window(app->mlx, app->window);
		mlx_destroy_display(app->mlx);
		free_exit(app->mlx, "Unable to create mlx window");
	}
	app->image.buffer = mlx_get_data_addr(app->image.ptr, &app->image.bpp,
			&app->image.length, &app->image.endian);
	setup_viewport(&app->view);
	setup_events(app);
}
