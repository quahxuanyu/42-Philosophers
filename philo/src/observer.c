/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:11:08 by xquah             #+#    #+#             */
/*   Updated: 2024/11/24 13:27:37 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_all_ate(t_philo *philos)
{
	int i;

	if (philos[0].num_must_eat = -1)
		return (0);
	i = -1;
	while (++i < philos[0].num_of_philo)
		if (philos[i].num_ate != philos[i].num_must_eat)
			return (0);
	return (1);
}

int check_dead_philo(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].num_of_philo)
	{
		if (philos[i].time_last_ate - get_current_time() > philos[i].time_to_die)
		{
			philos[i].dead = 1;
			return (1);
		}
	}
	return (0);
}

void monitor_routine(void *input)
{
	t_program *program;

	program = (t_program *)input;
	while (!check_all_ate(program->philos) || !check_dead_philo(program->philos))
		continue;
}