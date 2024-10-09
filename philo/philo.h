/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:02:15 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/24 19:02:37 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct t_list
{
	pthread_t		philo;
	pthread_mutex_t	forks;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	flag_mutex;
	pthread_mutex_t	curent_mutex;
	pthread_mutex_t	kla_mutex;
	pthread_mutex_t	*mutex_0;
	pthread_mutex_t	*mutex_1;
	pthread_mutex_t	*mutex_2;
	pthread_mutex_t	*mutex_3;
	int				id;
	long			last_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_philos;
	int				flag;
	long			curent;
	int				n_of_meals;
	int				kla;
}					t_data;

int		check(char **av, int *number_of_philosophers);
int		sub_atoi(char *str);
int		new_atoi(char *str);
void	error(void);
void	*monitoring_function(void *arg);
long	get_current_time_in_milliseconds(void);
int		eating(t_data *data);
int		sleeping(t_data *data);
int		thinking(t_data *data);
int		take_left_fork(t_data *data, int check);
int		take_right_fork(t_data *data, int check);
int		sleep_function(t_data *data, int time);
int		check_death(t_data *data);
long	get_current_time_in_milliseconds(void);
int		sleep_function(t_data *data, int time);
int		check_death(t_data *data);
void	put_down_forks(t_data *data);
int		initialize_data(t_data *data, int number_of_philosophers, char **av);
void	initialize_mutexes(t_data *data, int number_of_philosophers);
void	create_and_join_threads(t_data *data, int number_of_philosophers);
void	initialize_mutexes_2(t_data *data, int number_of_philosophers);
void	free_and_destroy_data(t_data *data, int n);
void	*action_function(void *arg);