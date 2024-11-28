/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:29:19 by xquah             #+#    #+#             */
/*   Updated: 2024/11/28 18:52:16 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	say_messaage("has taken a RIGHT fork", philo);
	pthread_mutex_lock(philo->left_fork);
	say_messaage("has taken a LEFT fork", philo);
	philo->is_eating = 1;
	say_messaage("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->num_ate += 1;
	philo->time_last_ate = get_current_time();
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	rest(t_philo *philo)
{
	say_messaage("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	think(t_philo *philo)
{
	say_messaage("is thinking", philo);
}