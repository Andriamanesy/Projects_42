/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:06:00 by briandri          #+#    #+#             */
/*   Updated: 2026/01/18 01:31:39 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

static int	check_death(t_data *d, int i)
{
	long	last_meal;

	pthread_mutex_lock(&d->meal_lock);
	last_meal = d->philos[i].last_meal;
	pthread_mutex_unlock(&d->meal_lock);
	if (get_time() - last_meal >= d->time_to_die)
	{
		print_status(&d->philos[i], "died");
		pthread_mutex_lock(&d->dead_lock);
		d->dead_flag = 1;
		pthread_mutex_unlock(&d->dead_lock);
		return (1);
	}
	return (0);
}

static int	check_meals(t_data *d)
{
	int	i;
	int	fed_count;

	if (d->nb_meals == -1)
		return (0);
	fed_count = 0;
	i = 0;
	while (i < d->nb_philos)
	{
		pthread_mutex_lock(&d->meal_lock);
		if (d->philos[i].meals_eaten >= d->nb_meals)
			fed_count++;
		pthread_mutex_unlock(&d->meal_lock);
		i++;
	}
	if (fed_count == d->nb_philos)
	{
		pthread_mutex_lock(&d->dead_lock);
		d->dead_flag = 1;
		pthread_mutex_unlock(&d->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*d;
	int		i;

	d = (t_data *)arg;
	while (!simulation_finished(d))
	{
		i = 0;
		while (i < d->nb_philos)
		{
			if (check_death(d, i))
				return (NULL);
			i++;
		}
		if (check_meals(d))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
