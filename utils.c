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

double	normalize(double val, t_range in)
{
	return ((val - in.min) / (in.max - in.min));
}

double	map_range(double normalized_val, t_range out)
{
	return (out.min + normalized_val * (out.max - out.min));
}

static double	handle_decimal_part(char *str, int *i)
{
	double	result;
	double	fraction;

	result = 0.0;
	fraction = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		{
			result += (str[*i] - '0') * fraction;
			fraction *= 0.1;
			(*i)++;
		}
	}
	return (result);
}

static double	handle_integer_part(char *str, int *i)
{
	double	result;

	result = 0.0;
	while (str[*i] && str[*i] != '.')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

double	parse_double(char *str)
{
	double	result;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (str[i] == '-' && str[i + 1])
	{
		sign = -1;
		i++;
	}
	result = handle_integer_part(str, &i);
	result += handle_decimal_part(str, &i);
	return (result * sign);
}
