/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:21:31 by nait-bou          #+#    #+#             */
/*   Updated: 2024/07/31 20:24:08 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	t_sleep(t_philo *philo)
{
	
}

void	t_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->num -1]);
	print_state("has taken a fork 🍴", philo);
	pthread_mutex_lock(&philo->data->fork[philo->num % philo->data->n_philo]);
	print_state("has taken a fork 🍴", philo);
	philo->data->last_eat[philo->num -1] = get_time();
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->data->fork[philo->num -1]);
	pthread_mutex_unlock(&philo->data->fork[philo->num % philo->data->n_philo]);
}

void	check_death(t_philo *ph)
{
	
}

void	start(void *arg)
{
	t_philo	*philo;
	int		eat;

	philo = (t_philo *)arg;
	eat = 0;
	if (philo->num % 2)
		usleep(100);
	while (1)
	{
		t_eat(philo);
		eat++;
		if (philo->data->n_to_eat != -1)
		{
			if (eat >= philo->data->n_to_eat)
				{
					philo->flag = 1;
					break ;
				}
		}
		t_sleep(philo);
		t_think(philo);
	}
}

void	philo(t_data *data)
{
	int	i;
	
	i = 0;
	data->current = get_time();
	data->die = 0;
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->n_philo)
	{
		data->last_eat[i] = get_time();
		pthread_create(&data->philo[i].ph, NULL, &start, &data->philo[i]);
		i++;
	}
	check_death(data->philo);
	i = 0;
	while (i < data->n_philo && data->die == 1)
	{
		pthread_join(data->philo[i].ph, NULL);
		i++;
	}
}