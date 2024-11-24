/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:34:06 by xquah             #+#    #+#             */
/*   Updated: 2024/11/24 13:28:57 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	routine(void *input)
{
	t_philo	*philo;
	philo = (t_philo *) input;
	while (1)
	{
		eat();
		sleep();
		think();
	}
}

void	create_threads(t_program *program)
{
	int			i;
	pthread_t	monitor;

	pthread_create(monitor, NULL, monitor_routine, (void *) program);
	i = -1;
	while (++i < program->philos[0].num_of_philo)
	{
		pthread_create(program->philos[i].thread, NULL, routine, (void *) &program->philos[i]);
	}
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < program->philos[0].num_of_philo)
	{
		pthread_join(program->philos[i].thread, NULL);
	}
}