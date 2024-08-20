/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:50 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/10 19:55:49 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
    int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
	}
	free(data->fork);
	free(data->last_eat);
	free(data->philo);
	pthread_mutex_destroy(&data->mutex);
}