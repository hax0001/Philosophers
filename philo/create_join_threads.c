/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_join_threads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:13 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/24 19:01:36 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_and_join_threads(t_data *data, int number_of_philosophers)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	while (i < number_of_philosophers)
	{
		data[i].id = i + 1;
		pthread_create(&data[i].philo, NULL, action_function, &data[i]);
		i++;
	}
	pthread_create(&monitor, NULL, monitoring_function, data);
	i = 0;
	pthread_join(monitor, NULL);
	while (i < number_of_philosophers)
	{
		pthread_join(data[i].philo, NULL);
		i++;
	}
}
