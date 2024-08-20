/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:21:31 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/20 12:50:53 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	t_sleep(t_philo *philo)
{
	if (print_state("is sleeping", philo))
		return (1);
	if (philo->data->t_die < philo->data->t_sleep)
		ft_usleep(philo->data->t_die, philo);
	else
		ft_usleep(philo->data->t_sleep, philo);
	return (0);
}
int odd_philolosophers(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->num -1]);
	if (print_state("has taken a fork", philo))
		return (pthread_mutex_unlock(&philo->data->fork[philo->num -1]) ,1);
	if (philo->data->n_philo == 1)
	return  pthread_mutex_unlock(&philo->data->fork[philo->num -1]), 1 ;
	pthread_mutex_lock(&philo->data->fork[philo->num % philo->data->n_philo]);
	if (print_state("has taken a fork", philo))
	{
		pthread_mutex_unlock(&philo->data->fork[philo->num -1]);
		pthread_mutex_unlock(&philo->data->fork[philo->num % philo->data->n_philo]);
		return (1);
	}
	if (print_state("is eating", philo))
	{
		pthread_mutex_unlock(&philo->data->fork[philo->num -1]);
		pthread_mutex_unlock(&philo->data->fork[philo->num % philo->data->n_philo]);
		return (1);
	}
	return(0);
}

int eaven_philolosophers(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->num % philo->data->n_philo]);
	if (print_state("has taken a fork", philo))
	{
		pthread_mutex_unlock(&philo->data->fork[philo->num % philo->data->n_philo]);
		return (1);
	}
	if (philo->data->n_philo == 1)
		return  pthread_mutex_unlock(&philo->data->fork[philo->num -1]), 1 ;
	pthread_mutex_lock(&philo->data->fork[philo->num -1]);
	if (print_state("has taken a fork", philo))
	{
		pthread_mutex_unlock(&philo->data->fork[philo->num -1]);
		pthread_mutex_unlock(&philo->data->fork[philo->num % philo->data->n_philo]);
		return (1);
	}
	if (print_state("is eating", philo))
	{
		pthread_mutex_unlock(&philo->data->fork[philo->num -1]);
		pthread_mutex_unlock(&philo->data->fork[philo->num % philo->data->n_philo]);
		return (1);
	}
	return(0);
}
int	t_eat(t_philo *philo)
{	
	if (philo->num % 2 == 0)
	{
		if(eaven_philolosophers(philo) == 1)
			return(1);
	}
	else
	{
		if(odd_philolosophers(philo) == 1)
			return(1);
	}
	pthread_mutex_lock(&philo->data->mutex1);
	philo->data->last_eat[philo->num -1] = get_time();
	pthread_mutex_unlock(&philo->data->mutex1);
	if (philo->data->t_die < philo->data->t_eat)
		ft_usleep(philo->data->t_die, philo);
	else
		ft_usleep(philo->data->t_eat, philo);
	pthread_mutex_unlock(&philo->data->fork[philo->num -1]);
	pthread_mutex_unlock(&philo->data->fork[philo->num % philo->data->n_philo]);
	return (0);
}

void	check_death(t_philo *ph)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < ph->data->n_philo)
		{
			pthread_mutex_lock(&ph[i].data->mutex1);
			ph->data->tmp1 = ph[i].data->last_eat[i];
			pthread_mutex_unlock(&ph[i].data->mutex1);
			if (ph[i].data->t_die <= get_time() - ph->data->tmp1)
			{
				if (ph[i].flag != 1)
					print_state("died ", &ph[i]);
				pthread_mutex_lock(&ph[i].data->mutex3);
				ph[i].data->die = 1;
				pthread_mutex_unlock(&ph[i].data->mutex3);
				printf(" \n %d \n",ph[i].num);
				break;
			}
			i++;
		}
		if (ph->data->die == 1)
			break;
	}
}

void	*start(void *arg)
{
	t_philo	*philo;
	int		eat;
	
	philo = (t_philo *)arg;
	eat = 0;
	if (philo->num % 2 == 0)
		ft_usleep(100, philo);
	//printf("===> %d bda\n", philo->num);
	while (1)
	{
		if (t_eat(philo))
			break;
		if (philo->data->n_to_eat != -1)
		{
			if (++eat >= philo->data->n_to_eat)
				{
					pthread_mutex_lock(&philo->data->mutex2);
					philo->flag = 1;
					pthread_mutex_unlock(&philo->data->mutex2);
					break ;
				}
		}
		if (t_sleep(philo) || t_think(philo))
			break;
	}
	return (NULL);
}

void	philo(t_data *data)
{
	int	i;
	
	i = 0;
	data->current = get_time();
	data->die = 0;
	pthread_mutex_init(&data->mutex, NULL);
	pthread_mutex_init(&data->mutex1, NULL);
	pthread_mutex_init(&data->mutex2, NULL);
	pthread_mutex_init(&data->mutex3, NULL);
	while (i < data->n_philo)
	{
		data->last_eat[i] = get_time();
		pthread_create(&data->philo[i].ph, NULL, &start, &data->philo[i]);
		i++;
	}
	check_death(data->philo);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philo[i].ph, NULL);
		i++;
	}
}
