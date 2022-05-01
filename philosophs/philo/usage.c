/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:26:54 by chorse            #+#    #+#             */
/*   Updated: 2022/05/01 19:55:40 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	j;
	short		sign;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (j * 10 + (sign * (str[i] - '0')) < j && sign > 0)
			return (-1);
		if (j * 10 + (sign * (str[i] - '0')) > j && sign < 0)
			return (0);
		j = j * 10 + (sign * (str[i] - '0'));
		i++;
	}
	return (j);
}

void	ft_sleep(long long msec)
{
	struct timeval				cur_time;
	unsigned long long			start_time;
	unsigned long long			end_time;
	unsigned long long			comparison;

	end_time = 0;
	start_time = ft_time();
	comparison = start_time + msec;
	usleep(1000 * msec - 2000);
	while (1)
	{
		gettimeofday(&cur_time, NULL);
		end_time = cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000;
		if (end_time >= comparison)
		{
			return ;
		}
		usleep(250);
	}
}

int	check_time(t_data *data)
{
	if (((3 * data->eating_time > data->lifetime) && \
		data->number % 2 != 0) || ((data->number % 2 == 0) && \
			(2 * data->eating_time > data->lifetime)))
		return (1);
	return (0);
}

int	valid_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_circle(t_data *data, int i)
{
	pthread_mutex_lock(data->philo[i].num_times);
	if (data->philo[i].cycles == 0)
	{
		kill_philo(data);
		destroy_mt(data);
		// pthread_mutex_unlock(data->philo[i].num_times);
		return (0);
	}
	pthread_mutex_unlock(data->philo[i].num_times);
	return (1);
}
