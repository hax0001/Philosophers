/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:01:12 by nait-bou          #+#    #+#             */
/*   Updated: 2024/08/24 19:01:29 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data *data;
	int number_of_philosophers;

	if (ac < 5 || ac > 6)
	{
        error();
        return(1);
	}
	if (check(av, &number_of_philosophers) == 1)
		return (1);
	data = malloc(number_of_philosophers * sizeof(t_data));
	if (!data)
		return (1);
	if (initialize_data(data, number_of_philosophers, av) == 1)
		return (1);
	initialize_mutexes(data, number_of_philosophers);
	initialize_mutexes_2(data, number_of_philosophers);
	create_and_join_threads(data, number_of_philosophers);
	free_and_destroy_data(data, number_of_philosophers);
}
