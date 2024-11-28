/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:11:08 by xquah             #+#    #+#             */
/*   Updated: 2024/11/28 20:25:00 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_all_ate(t_philo *philos)
{
	int i;
	
	if (philos[0].num_must_eat == -1)
	{
		return (0);
	}
	i = -1;
	while (++i < philos[0].num_of_philo)
	{
		if (philos[i].num_ate < philos[i].num_must_eat)
			return (0);
	}
	*(philos[0].dead) = 1;
	return (1);
}

int philosopher_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->time_last_ate >= philo->time_to_die && philo->is_eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}


int check_dead_philo(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].num_of_philo)
	{
		if (philosopher_dead(philos))
		{
			say_messaage("died", &(philos[i]));
			pthread_mutex_lock(philos[0].dead_lock);
			*(philos[i].dead) = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
	}
	return (0);
}

void	*monitor_routine(void *input)
{
	t_program *program;

	program = (t_program *) input;
	while (!check_all_ate(program->philos) && !check_dead_philo(program->philos))
		continue ;	
	return (NULL);
}