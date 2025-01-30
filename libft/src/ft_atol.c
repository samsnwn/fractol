#include "libft.h"

long ft_atol(const char *str)
{
    long result = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str)
    {
        if (*str < '0' || *str > '9')
            break;
        if (result > (LONG_MAX - (*str - '0')) / 10)
        {
            if (sign == 1)
                return LONG_MAX;
            else
                return LONG_MIN;
        }
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}