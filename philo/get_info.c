/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:19:31 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 10:55:40 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    get_info(int ac, char **str, t_data *data)
{
    data->n_philo = new_atoi(str[1]);
    data->t_die = new_atoi(str[2]);
    data->t_eat = new_atoi(str[3]);
    data->t_sleep = new_atoi(str[4]);
    if (ac == 6)
        data->n_to_eat = new_atoi(str[5]);
    else
        data->n_to_eat = -1;
}