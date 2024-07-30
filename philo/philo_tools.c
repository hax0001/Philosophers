/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:48:54 by nait-bou          #+#    #+#             */
/*   Updated: 2024/07/27 17:48:31 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sub_atoi(char *str)
{
    long r;

    r = 0;
    while (*str)
	{
		if (*str < '0' || *str > '9')
        {
            error();
            return (-1);
        }
		r = r * 10 + *(str++) - '0';
	}
	if ((r) > 2147483647 || (r) < -2147483648)
	{
		error();
        return (-1);
    }
    return (r);
}

int	new_atoi(char *str)
{
	long	r;

	r = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-' && *(str + 1) == '\0') || (*str == '+' && *(str
				+ 1) == '\0'))
    {
		error();
        return (-1);
    }
	if (*str == '-')
	{
		error();
        return (-1);
	}
	if (*str == '+')
		str++;
    r = sub_atoi(str);

	return (r);
}

long	long	get_time(void)
{
	struct timeval	t_m;

	if (gettimeofday(&t_m, NULL) == -1)
		ft_error();
	return ((t_m.tv_sec * 1000) + (t_m.tv_usec / 1000));
}