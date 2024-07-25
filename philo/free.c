/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:50 by nait-bou          #+#    #+#             */
/*   Updated: 2024/07/25 13:05:36 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data data)
{
	int	i;
	
	i = 0;
	while (i < data.n_philo)
	{
		free(data.last_eat[i]);
		
	}
	data.n_philo = 0;
	data.n_to_eat = 0;
	data.t_die = 0;
	data.t_eat = 0;
	data.t_speep = 0;
}