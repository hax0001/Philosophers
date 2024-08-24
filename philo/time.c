/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:03:09 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/24 19:03:14 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time_in_milliseconds(void)
{
	struct timeval	tv;
	int				res;

	gettimeofday(&tv, NULL);
	res = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (res);
}

int	sleep_function(t_data *data, int time)
{
	int	db;
	int	curent;
	int	gbil;

	pthread_mutex_lock(&data->curent_mutex);
	curent = data->curent;
	pthread_mutex_unlock(&data->curent_mutex);
	gbil = (get_current_time_in_milliseconds() - curent);
	db = 0;
	while (1)
	{
		db = (get_current_time_in_milliseconds() - curent);
		if ((db - gbil) >= time)
			break ;
		pthread_mutex_lock(&data->flag_mutex);
		if (data->flag)
		{
			pthread_mutex_unlock(&data->flag_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->flag_mutex);
		usleep(100);
	}
	return (0);
}

int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->flag_mutex);
	if (data->flag)
	{
		pthread_mutex_unlock(&data->flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->flag_mutex);
	return (0);
}

void	put_down_forks(t_data *data)
{
	pthread_mutex_unlock(data->left_fork);
	pthread_mutex_unlock(data->right_fork);
}
