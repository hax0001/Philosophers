/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:19:31 by nait-bou          #+#    #+#             */
/*   Updated: 2024/07/25 11:42:06 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    get_info(int ac, char **str, t_data data)
{
    data.n_philo = new_atoi(str[1], data);
    data.t_die = new_atoi(str[2], data);
    data.t_eat = new_atoi(str[3], data);
    data.t_speep = new_atoi(str[4], data);
    if (ac == 6)
        data.n_to_eat = new_atoi(str[5], data);
    else
        data.n_to_eat = -1;
}