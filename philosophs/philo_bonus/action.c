/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:08:12 by ysachiko          #+#    #+#             */
/*   Updated: 2022/05/02 15:27:32 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	take_forks(t_data *data, int id)
{
	sem_wait(data->general);
	sem_wait(data->forks);
	ft_print_msg(data, 'f', id);
	sem_wait(data->forks);
	ft_print_msg(data, 'f', id);
	sem_post(data->general);
}

int	check_death(t_data *data)
{
	sem_wait(data->print);
	// printf("ALOS = %lld\n", ft_time() - data->last_meal);
	if (ft_time() - data->last_meal > data->die_time)
	{
		printf("Философ сдох\n");
		exit(1);
	}
	sem_post(data->print);
	return (0);
}

void	ft_action(t_data *data, int id)
{
	// update_time(data);
	while (1)
	{
		take_forks(data, id);
		check_death(data);
		eating(data, id);
		sleeping(data, id);
		if (data->eat != -1)
			data->cycles--;
		if (data->cycles == 0)
			exit (0);
	}
	exit (1);
}

void	eating(t_data *data, int id)
{
	ft_print_msg(data, 'e', id);
	ft_sleep(data->eat_time);
	data->last_meal = ft_time();
	sem_post(data->forks);
	sem_post(data->forks);
}

void	sleeping(t_data *data, int id)
{
	ft_print_msg(data, 's', id);
	ft_sleep(data->sleep_time);
	ft_print_msg(data, 't', id);
}
