/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:38:13 by nait-bou          #+#    #+#             */
/*   Updated: 2024/07/25 12:32:53 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data  data;

   memset(&data, 0, sizeof(t_data));
   if (ac < 5 || ac > 6)
   {
        error();
        free_all(data);
        return(1);
   }
   if (check(av, data) == 1)
        return (1);
    get_info(ac, av, data);
    if (init_struct(data) == 1)
        return (1);
    return (0);
}