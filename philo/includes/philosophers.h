/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:14:50 by xquah             #+#    #+#             */
/*   Updated: 2024/11/28 19:55:42 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

#define MAX_PHILO 250

typedef struct s_philo {
	int				id;
	int				*dead;
	int				is_eating;
	pthread_t		thread;
	size_t			num_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_must_eat;
	int				num_ate;
	size_t 			start_time;
	size_t			time_last_ate;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *dead_lock;
	pthread_mutex_t *meal_lock;
	pthread_mutex_t *write_lock;
} t_philo;

typedef struct s_program
{
	int		dead_status;
	pthread_mutex_t dead_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t write_lock;
	t_philo	*philos;
} t_program;

void	initialize_input(int argc, char *argv[], t_philo philo[MAX_PHILO]);
void	initialize_forks(pthread_mutex_t forks[MAX_PHILO]);
void	initialize_philo(t_philo philos[MAX_PHILO], pthread_mutex_t forks[MAX_PHILO], t_program *program);
void	create_threads(t_program *program);
void	*monitor_routine(void *input);
int		ft_atoi(const char *str);
void	run_philo(t_philo philos[MAX_PHILO]);
size_t	get_current_time(void);
void	wait_for(int milli);

//EXECUTION.C
int	check_dead_loop(t_philo *philo);	

// ROUTINE.C
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	rest(t_philo *philo);

//UTILS.C
int		ft_usleep(size_t milliseconds);
void	say_messaage(char *str, t_philo *philo);
#endif