/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:30:10 by briandri          #+#    #+#             */
/*   Updated: 2026/01/03 11:14:48 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	start_simulation(t_data *data)
{
	int	i;

	data->start_time = get_time() + (data->nb_philos * 2);
	i = -1;
	while (++i < data->nb_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		data->philos[i].last_meal = data->start_time;
		pthread_mutex_unlock(&data->meal_lock);
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				&data->philos[i]))
			return (1);
	}
	monitor_routine(data);
	while (get_time() < data->start_time)
		usleep(100);
	monitor_routine(data);
	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philos[i].thread, NULL);
	return (0);
}

int	simulation_finished(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->dead_lock);
	res = data->dead_flag;
	pthread_mutex_unlock(&data->dead_lock);
	return (res);
}
