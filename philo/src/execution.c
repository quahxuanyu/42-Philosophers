/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:34:06 by xquah             #+#    #+#             */
/*   Updated: 2024/11/28 19:23:18 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead) == 1)
	{
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*routine(void *input)
{
	t_philo	*philo;

	philo = (t_philo *) input;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!check_dead_loop(philo))
	{
		eat(philo);
		rest(philo);
		think(philo);
	}
	return (NULL);
}

void	create_threads(t_program *program)
{
	int			i;
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitor_routine, (void *) program);
	i = -1;
	while (++i < program->philos[0].num_of_philo)
	{
		pthread_create(&(program->philos[i].thread), NULL, routine, (void *) &(program->philos[i]));
	}
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < program->philos[0].num_of_philo)
	{
		pthread_join(program->philos[i].thread, NULL);
	}
}