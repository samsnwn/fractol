#include "fractol.h"

static void	setup_viewport(t_viewport *view)
{
	view->center_x = 0.0;
	view->center_y = 0.0;
	view->scale = 1.0;
	view->max_iter = MAX_ITERATIONS;
}

static void	setup_events(t_app *app)
{
	mlx_hook(app->window, KeyPress, 0, on_key_press, app);
	mlx_hook(app->window, ButtonPress, 0, on_mouse_scroll, app);
	mlx_hook(app->window, DestroyNotify, 0, on_window_close, app);
	mlx_hook(app->window, MotionNotify, 0, on_mouse_move, app);
}

void	init_app(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		exit(EXIT_FAILURE);
	app->window = mlx_new_window(app->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			app->fractal_type);
	if (!app->window)
		// mlx_destroy_display(fractol->mlx); !! solo para linux
		free_exit(app->mlx, "Unable to create mlx connection");
	app->image.ptr = mlx_new_image(app->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!app->image.ptr)
	{
		mlx_destroy_window(app->mlx, app->window);
		// mlx_destroy_display(fractol->mlx); !! solo para linux
		free_exit(app->mlx, "Unable to create mlx window");
	}
	app->image.buffer = mlx_get_data_addr(app->image.ptr, &app->image.bpp,
			&app->image.length, &app->image.endian);
	setup_viewport(&app->viewport);
	setup_events(app);
}