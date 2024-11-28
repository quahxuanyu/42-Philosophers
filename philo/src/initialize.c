/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:56:08 by xquah             #+#    #+#             */
/*   Updated: 2024/11/28 12:30:40 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	initialize_input(int argc, char *argv[], t_philo philo[MAX_PHILO])
{
	int	num_of_philo;

	if (argc == 5 || argc == 6)
	{
		num_of_philo = ft_atoi(argv[1]);
		while (num_of_philo--)
		{
			// printf("Philo %i: has this time to die %i\n", num_of_philo, ft_atoi(argv[2]));
			philo[num_of_philo].num_of_philo = ft_atoi(argv[1]);
			philo[num_of_philo].time_to_die = ft_atoi(argv[2]);
			philo[num_of_philo].time_to_eat = ft_atoi(argv[3]);
			philo[num_of_philo].time_to_sleep = ft_atoi(argv[4]);
			if (argc == 6)
				philo[num_of_philo].num_must_eat = ft_atoi(argv[5]);
			else
				philo[num_of_philo].num_must_eat = -1;
		}
	}
}

void	initialize_forks(pthread_mutex_t forks[MAX_PHILO])
{
	int	i;

	i = MAX_PHILO;
	while (i--)
		pthread_mutex_init(&forks[i], NULL);
}

void	initialize_philo(t_philo philos[MAX_PHILO],
	pthread_mutex_t forks[MAX_PHILO], t_program *program)
{
	int	i;

	i = philos[0].num_of_philo;
	while (i--)
	{
		philos[i].id = i + 1;
		philos[i].right_fork = &forks[i];
		philos[i].dead = &(program->dead_status);
		philos[i].num_ate = 0;
		philos[i].start_time = get_current_time();
		philos[i].time_last_ate = get_current_time();
		philos[i].dead_lock = &(program->dead_lock);
		philos[i].meal_lock = &(program->meal_lock);
		philos[i].write_lock = &(program->meal_lock);
		if (i == 0)
			philos[i].left_fork = &forks[philos[0].num_of_philo - 1];
		else
			philos[i].left_fork = &forks[i - 1];
	}
}