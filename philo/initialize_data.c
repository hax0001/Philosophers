/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:59 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/24 19:01:32 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_mutexes(t_data *data, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&data[i].forks, NULL);
		pthread_mutex_init(&data[i].meal_mutex, NULL);
		pthread_mutex_init(&data[i].flag_mutex, NULL);
		pthread_mutex_init(&data[i].curent_mutex, NULL);
		pthread_mutex_init(&data[i].kla_mutex, NULL);
		i++;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		data[i].left_fork = &data[i].forks;
		data[i].right_fork = &data[(i + 1) % number_of_philosophers].forks;
		i++;
	}
}

void	initialize_mutexes_2(t_data *data, int number_of_philosophers)
{
	static pthread_mutex_t	mutex_0 = PTHREAD_MUTEX_INITIALIZER;
	static pthread_mutex_t	mutex_1 = PTHREAD_MUTEX_INITIALIZER;
	static pthread_mutex_t	mutex_2 = PTHREAD_MUTEX_INITIALIZER;
	static pthread_mutex_t	mutex_3 = PTHREAD_MUTEX_INITIALIZER;
	int						i;

	i = 0;
	while (i < number_of_philosophers)
	{
		data[i].mutex_0 = &mutex_0;
		data[i].mutex_1 = &mutex_1;
		data[i].mutex_2 = &mutex_2;
		data[i].mutex_3 = &mutex_3;
		i++;
	}
}

int	initialize_data(t_data *data, int number_of_philosophers, char **av)
{
	int	number_of_meals;
	int	time_to_sleep;
	int	time_to_die;
	int	time_to_eat;
	int	b;

	b = 0;
	time_to_die = new_atoi(av[2]);
	time_to_eat = new_atoi(av[3]);
	time_to_sleep = new_atoi(av[4]);
	if (av[5])
		number_of_meals = new_atoi(av[5]);
	if (b)
		return (error(), 1);
	while (b < number_of_philosophers)
	{
		data[b].time_to_die = time_to_die;
		data[b].time_to_eat = time_to_eat;
		data[b].time_to_sleep = time_to_sleep;
		data[b].n_of_meals = number_of_meals;
		data[b].n_of_philos = number_of_philosophers;
		data[b].flag = 0;
		b++;
	}
	return (0);
}
