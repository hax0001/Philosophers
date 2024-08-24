/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:01:53 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/24 19:01:56 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(char **av, 	int	*number_of_philosophers)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (new_atoi(av[i]) == (-1))
			return (1);
		i++;
	}
	*number_of_philosophers = new_atoi(av[1]);
	if (*number_of_philosophers == 0)
		return (error() ,1);
	return (0);
}

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
	if ((*str == '-' && *(str + 1) == '\0') || (*str == '+' && *(str + 1) == '\0'))
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

void	error(void)
{
	printf("\n ERROR ! \n");
}

