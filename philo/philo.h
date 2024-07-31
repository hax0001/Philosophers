/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:38:17 by nait-bou          #+#    #+#             */
/*   Updated: 2024/07/31 20:23:32 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>


#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BLUE    "\x1b[34m"
#define YELLOW  "\x1b[33m"

typedef struct philo
{
    struct s_data      *data;    
    int     num;
    int     flag;
    pthread_t   ph;
    
}t_philo;

typedef struct s_data
{
    t_philo         *philo;
    pthread_mutex_t *fork;
    pthread_mutex_t mutex;
    long long       *last_eat;
    int             n_philo;
    int             t_die;
    int             t_eat;
    int             t_sleep;
    int             n_to_eat;
    int             die;
    long long       current;
    
}t_data;



void	error(void);
void	free_all(t_data *data);
int	new_atoi(char *str);
int	sub_atoi(char *str);
int	check(char **av);
void    get_info(int ac, char **str, t_data *data);
int	init_struct(t_data *data);
long	long	get_time(void);
void	philo(t_data *dat);
void	start(void *arg);
void	check_death(t_philo *ph);
void	t_eat(t_philo *philo);
void	print_state(char *str, t_philo *philo);
void	ft_usleep(int tie);
void	t_sleep(t_philo *philo);
void    t_think(t_philo *philo);

#endif