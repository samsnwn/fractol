/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:07:04 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/05 18:11:56 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/include/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 800
# define MAX_ITERATIONS 150

# define COLOR_BACKGROUND 0x000000
# define COLOR_FOREGROUND 0xFFFFFF
# define COLOR_HIGHLIGHT 0xFF0000

# ifdef __APPLE__
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_PLUS 69
#  define KEY_MINUS 78
#  define KEY_ESC 53
# else
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_PLUS 65451
#  define KEY_MINUS 65453
#  define KEY_ESC 65307
# endif

typedef struct s_image
{
	void		*ptr;
	char		*buffer;
	int			bpp;
	int			length;
	int			endian;
}				t_image;

typedef struct s_viewport
{
	double		center_x;
	double		center_y;
	double		scale;
	int			max_iter;
	double		julia_real;
	double		julia_imag;
}				t_viewport;

typedef struct s_app
{
	void		*mlx;
	void		*window;
	char		*fractal_type;
	t_image		image;
	t_viewport	viewport;
}				t_app;

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

// Core functions
void			init_app(t_app *app);
void			render_fractal(t_app *app);

// Event handlers
int				on_key_press(int key, t_app *app);
int				on_mouse_scroll(int button, int x, int y, t_app *app);
int				on_mouse_move(int x, int y, t_app *app);
int				on_close(t_app *app);

// Math utilities
t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_multiply(t_complex a, t_complex b);
double			map_range(double val, double in_min, double in_max, double out_min, double out_max);
double			parse_double(char *str);

void			print_usage(void);
void			free_exit(void *mlx, char *message);

#endif
