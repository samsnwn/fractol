#include "fractol.h"

double	scale_value(double value, double input_min, double input_max,
		double output_min, double output_max)
{
	return (output_min + (value - input_min) * (output_max - output_min)
		/ (input_max - input_min));
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.x = z.x * z.x - z.y * z.y; // Real part: a^2 - b^2
	res.y = 2 * z.x * z.y;         // Imaginary part: 2ab
	return (res);
}

double	string_to_double(char *str)
{
	double result = 0.0;
	double decimal_place = 1.0;
	int sign = 1;
	int i = 0;

	// Handle optional sign
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	// Process the integer part
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	// Process the decimal part if present
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			decimal_place *= 0.1;
			result += (str[i] - '0') * decimal_place;
			i++;
		}
	}
	return (result * sign);
}