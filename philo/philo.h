/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:38:17 by nait-bou          #+#    #+#             */
/*   Updated: 2024/07/25 12:31:56 by nait-bou         ###   ########.fr       */
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

typedef struct s_data
{
    int             n_philo;
    int             t_die;
    int             t_eat;
    int             t_speep;
    int             n_to_eat;
    t_philo         *philo;
    pthread_mutex_t *fork;
    long long       *last_eat;
    
}t_data;

typedef struct s_philo
{
    

    
}t_philo;


void	error(void);
void	free_all(t_data data);
int	new_atoi(char *str, t_data data);
int	sub_atoi(char *str, t_data data);
int	check(char **av, t_data data);
void    get_info(int ac, char **str, t_data data);
int	init_struct(t_data data);

#endif