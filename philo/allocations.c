/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:23:05 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 13:10:55 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_struct(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	data->last_eat = malloc(sizeof(long long) * data->n_philo);
	if (!data->philo || !data->fork || !data->last_eat)
	{
		error();
		free_all(data);
		return (1);
	}
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		data->philo[i].data = data;
		data->philo[i].num = i + 1;
		data->philo[i].flag = 0;
		i++;
	}
	return (0);
}
