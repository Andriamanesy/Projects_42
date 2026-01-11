/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:06:00 by briandri          #+#    #+#             */
/*   Updated: 2026/01/03 11:16:21 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	check_death(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (get_time() - data->philos[i].last_meal >= data->time_to_die)
		{
			print_status(&data->philos[i], "died");
			pthread_mutex_lock(&data->dead_lock);
			data->dead_flag = 1;
			pthread_mutex_unlock(&data->dead_lock);
			pthread_mutex_unlock(&data->meal_lock);
			return (1);
		}
		pthread_mutex_unlock(&data->meal_lock);
	}
	return (0);
}

int	all_philos_fed(t_data *data)
{
	int	i;
	int	finished_eating;

	if (data->nb_meals == -1)
		return (0);
	i = 0;
	finished_eating = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (data->philos[i].meals_eaten >= data->nb_meals)
			finished_eating++;
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	return (finished_eating == data->nb_philos);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = -1;
		while (++i < data->nb_philos)
		{
			if (is_dead(&data->philos[i]))
			{
				print_death(&data->philos[i]);
				return (NULL);
			}
		}
		if (data->nb_meals != -1 && all_philos_fed(data))
		{
			pthread_mutex_lock(&data->dead_lock);
			data->dead_flag = 1;
			pthread_mutex_unlock(&data->dead_lock);
			return (NULL);
		}
		usleep(100);
	}
}

int	is_dead(t_philo *philo)
{
	long	now;

	pthread_mutex_lock(&philo->data->meal_lock);
	now = get_time();
	if (now - philo->last_meal >= philo->data->time_to_die)
	{
		pthread_mutex_unlock(&philo->data->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->meal_lock);
	return (0);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (!philo->data->dead_flag)
	{
		philo->data->dead_flag = 1;
		printf("%ld %d died\n", get_time() - philo->data->start_time,
			philo->id);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
}
