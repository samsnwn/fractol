#include "fractol.h"

void	events(t_fractol *fractol)
{
	mlx_hook(fractol->win, KeyPress, 0, handle_key, fractol);
	mlx_hook(fractol->win, ButtonPress, 0, handle_mouse, fractol);
	mlx_hook(fractol->win, DestroyNotify, 0, handle_close, fractol);
	mlx_hook(fractol->win, MotionNotify, 0, handle_julia, fractol);
}

void	start_data(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_definiton = 100;
	fractol->shift_x = 0;
	fractol->shift_y = 0;
	fractol->zoom = 1;
}

void	start_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		exit(EXIT_FAILURE);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	if (fractol->win == NULL)
	{
		// mlx_destroy_display(fractol->mlx); !! solo para linux
		free_exit(fractol->mlx, "Unable to create mlx connection");
	}
	fractol->image.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->image.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		// mlx_destroy_display(fractol->mlx); !! solo para linux
		free_exit(fractol->mlx, "Unable to create mlx window");
	}
	fractol->image.addr = mlx_get_data_addr(fractol->image.img_ptr,
			&fractol->image.bits_per_pixel, &fractol->image.len,
			&fractol->image.endian);

	events(fractol);
	start_data(fractol);
}