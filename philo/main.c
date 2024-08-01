/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:38:13 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 10:56:46 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    t_think(t_philo *philo)
{
	print_state("is thinking ", philo);	
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
    return (0);
}