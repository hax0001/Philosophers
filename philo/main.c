/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:38:13 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/20 12:53:32 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    t_think(t_philo *philo)
{
	if (print_state("is thinking", philo))
        return (1);
    ft_usleep(1, philo);
    return (0);
}

int main(int ac, char **av)
{
    t_data  data;

   if (ac < 5 || ac > 6)
   {
        error();
        return(1);
   }
   if (check(av) == 1)
        return (1);
    get_info(ac, av, &data);
    if (init_struct(&data) == 1)
        return (1);
    philo(&data);
    free_all(&data);
    return (0);
}
