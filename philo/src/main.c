/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:09:32 by xquah             #+#    #+#             */
/*   Updated: 2024/11/26 23:05:07 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int argc, char *argv[])
{
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];
	t_program		program;

	if (argc != 5 && argc != 6)
		return (write(2, "Wrong argument count\n", 22), 1);
	program.philos = philos;
	initialize_input(argc, argv, philos);
	initialize_forks(forks);
	initialize_philo(philos, forks, &program);
	create_threads(&program);
	// printf("Philo %i's left fork address: %p\n", philos[0].id, philos[0].left_fork);
	// printf("Philo %i's right fork address: %p\n", philos[philos[0].num_of_philo - 1].id, philos[philos[0].num_of_philo - 1].right_fork);
}