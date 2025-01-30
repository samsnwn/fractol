#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/include/libft.h"
# include "./minilibx_macos/mlx.h"
# include <X11/X.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# ifdef __APPLE__
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define PLUS_KEY 69
#  define MINUS_KEY 78
#  define ESC_KEY 53
# elif defined(__linux__)
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define PLUS_KEY 61
#  define MINUS_KEY 45
#  define ESC_KEY 65307
# endif

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		len;

}			t_image;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	char	*name;
	double	escape_value;
	int		iterations_definiton;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double julia_x;
	double julia_y;

	t_image	image;

}			t_fractol;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

void		start_fractol(t_fractol *fractol);
void		draw_fractol(t_fractol *fractol);

int			handle_key(int key_code, t_fractol *fractol);
int			handle_mouse(int button, int x, int y, t_fractol *fractol);
int			handle_close(t_fractol *fractol);
int 		handle_julia(int x, int y, t_fractol *fractol);

double		scale_value(double value, double input_min, double input_max,
				double output_min, double output_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double	string_to_double(char *str);

void		free_exit(void *mlx, char *message);

#endif