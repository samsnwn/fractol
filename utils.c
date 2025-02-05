/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:09:53 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/05 18:09:55 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	return ((t_complex){.real = a.real + b.real, .imag = a.imag + b.imag});
}

t_complex	complex_multiply(t_complex a, t_complex b)
{
	return ((t_complex){.real = a.real * b.real - a.imag * b.imag,
		.imag = a.real * b.imag + a.imag * b.real});
}

double	map_range(double val, double in_min, double in_max, double out_min,
		double out_max)
{
	return (out_min + ((val - in_min) * (out_max - out_min)) / (in_max
			- in_min));
}

double	parse_double(char *str)
{
	double		result;
	double		fraction;
	int			sign;
	int			i;

	result = 0.0;
	fraction = 0.1;
	sign = 1;
	i = 0;
	if (str[i] == '-' && str[i + 1])
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - '0') * fraction;
			fraction *= 0.1;
			i++;
		}
	}
	return (result * sign);
}
