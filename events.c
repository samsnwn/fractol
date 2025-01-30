#include "fractol.h"

int	handle_close(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->image.img_ptr);
	mlx_destroy_window(fractol->mlx, fractol->win);
	// mlx_destroy_display(); Only for linux
	free(fractol->mlx);
	exit(EXIT_SUCCESS);
}

int	handle_key(int key_code, t_fractol *fractol)
{
	if (key_code == ESC_KEY)
		handle_close(fractol);
	else if (key_code == RIGHT_KEY)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (key_code == LEFT_KEY)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (key_code == UP_KEY)
		fractol->shift_y +=(0.5 * fractol->zoom);
	else if (key_code == DOWN_KEY)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (key_code == PLUS_KEY)
		fractol->iterations_definiton += 10;
	else if (key_code == MINUS_KEY)
		fractol->iterations_definiton -= 10;
	draw_fractol(fractol);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *fractol)
{
	if (button == Button5)
	{
		// Zoom out
    fractol->zoom *= 1.05;
	}
	else if (button == Button4)
	{
		// Zoom in
    fractol->zoom *= 0.95;
	}
	draw_fractol(fractol);
	return (0);
}

int handle_julia(int x, int y, t_fractol *fractol)
{
  if(!ft_strncmp(fractol->name, "julia", 5))
  {
    fractol->julia_x = scale_value(x, 0, WIDTH, -2, 2) * fractol->zoom + fractol->shift_x;
    fractol->julia_y = scale_value(x, 0, HEIGHT, 2, -2) * fractol->zoom + fractol->shift_y;
  }
  draw_fractol(fractol);
  return 0;
}