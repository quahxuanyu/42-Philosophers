/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:38:12 by xquah             #+#    #+#             */
/*   Updated: 2024/11/28 18:06:45 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	is_negative;

	i = -1;
	num = 0;
	is_negative = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		is_negative = (*str == '-');
		str++;
	}
	while (str[++i] >= '0' && str[i] <= '9')
		num = (num * 10) + str[i] - '0';
	if (is_negative)
		num = num * -1;
	return (num);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	say_messaage(char *str, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!check_dead_loop(philo))
		printf("%zu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}