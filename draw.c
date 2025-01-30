#include "fractol.h"

void	my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->len) + (x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->addr + offset) = color;
}

void mandelbrot_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	check_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (scale_value(x, 0, WIDTH, -2, 2) * fractol->zoom) + fractol->shift_x;
	z.y = (scale_value(y, 0, HEIGHT, 2, -2) * fractol->zoom) + fractol->shift_y;

	mandelbrot_julia(&z, &c, fractol);
	while (i < fractol->iterations_definiton)
	{
		z = sum_complex(square_complex(z), c);
		if (z.x * z.x + z.y * z.y > fractol->escape_value)
		{
			color = scale_value(i, 0, fractol->iterations_definiton, BLACK,
					WHITE);
			my_pixel_put(x, y, &fractol->image, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractol->image, WHITE);
}

void	draw_fractol(t_fractol *fractol)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			check_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image.img_ptr,
		0, 0);
}