/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:02:48 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/24 19:02:57 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_data *data)
{
	long	curent_time;

	curent_time = 0;
	pthread_mutex_lock(data->mutex_0);
	if (check_death(data))
	{
		pthread_mutex_unlock(data->mutex_0);
		pthread_mutex_unlock(data->right_fork);
		pthread_mutex_unlock(data->left_fork);
		return (1);
	}
	curent_time = (get_current_time_in_milliseconds() - data->curent);
	printf("%ld %d is eating\n", curent_time, data->id);
	pthread_mutex_unlock(data->mutex_0);
	pthread_mutex_lock(&data->meal_mutex);
	data->last_meal = get_current_time_in_milliseconds();
	pthread_mutex_unlock(&data->meal_mutex);
	if (sleep_function(data, data->time_to_eat) == 1)
	{
		pthread_mutex_unlock(data->right_fork);
		pthread_mutex_unlock(data->left_fork);
		return (1);
	}
	return (0);
}

int	sleeping(t_data *data)
{
	long	curent_time;

	curent_time = 0;
	pthread_mutex_lock(data->mutex_1);
	if (check_death(data))
	{
		pthread_mutex_unlock(data->mutex_1);
		return (1);
	}
	curent_time = (get_current_time_in_milliseconds() - data->curent);
	printf("%ld %d is sleeping\n", curent_time, data->id);
	pthread_mutex_unlock(data->mutex_1);
	if (sleep_function(data, data->time_to_sleep) == 1)
		return (1);
	return (0);
}

int	thinking(t_data *data)
{
	long	curent_time;

	curent_time = 0;
	pthread_mutex_lock(data->mutex_2);
	if (check_death(data))
	{
		pthread_mutex_unlock(data->mutex_2);
		return (1);
	}
	curent_time = (get_current_time_in_milliseconds() - data->curent);
	printf("%ld %d is thinking\n", curent_time, data->id);
	pthread_mutex_unlock(data->mutex_2);
	return (0);
}

int	take_left_fork(t_data *data, int check)
{
	long	curent_time;

	curent_time = 0;
	if (check_death(data))
	{
		if (check)
			pthread_mutex_unlock(data->right_fork);
		return (1);
	}
	pthread_mutex_lock(data->left_fork);
	if (check_death(data))
	{
		pthread_mutex_unlock(data->left_fork);
		if (check)
			pthread_mutex_unlock(data->right_fork);
		return (1);
	}
	curent_time = (get_current_time_in_milliseconds() - data->curent);
	printf("%ld %d has taken a fork\n", curent_time, data->id);
	return (0);
}

int	take_right_fork(t_data *data, int check)
{
	long	curent_time;

	curent_time = 0;
	if (data->id % 2 == 1)
		usleep(100);
	if (check_death(data))
	{
		if (check)
			pthread_mutex_unlock(data->left_fork);
		return (1);
	}
	pthread_mutex_lock(data->right_fork);
	if (check_death(data))
	{
		pthread_mutex_unlock(data->right_fork);
		if (check)
			pthread_mutex_unlock(data->left_fork);
		return (1);
	}
	curent_time = (get_current_time_in_milliseconds() - data->curent);
	printf("%ld %d has taken a fork\n", curent_time,
		data->id);
	return (0);
}
