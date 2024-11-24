/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:29:19 by xquah             #+#    #+#             */
/*   Updated: 2024/11/24 14:15:09 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);

}

void	eat(t_philo philo)
{
	pthread_mutex_lock(philo.right_fork);
	printf("%i %i has taken a fork\n", get_current_time - philo.start_time, philo.id);
	pthread_mutex_lock(philo.left_fork);
	printf("%i %i has taken a fork\n", get_current_time - philo.start_time, philo.id);
	printf("%i %i is eating\n", get_current_time - philo.start_time, philo.id);
	wait_for(philo.time_to_eat);
	pthread_mutex_unlock(philo.right_fork);
	pthread_mutex_unlock(philo.left_fork);
}

void	sleep()
{

}

void	think()
{
	
}