/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:30:10 by briandri          #+#    #+#             */
/*   Updated: 2026/01/18 03:18:49 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	simulation_finished(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->dead_lock);
	res = data->dead_flag;
	pthread_mutex_unlock(&data->dead_lock);
	return (res);
}

static int	spawn_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].last_meal = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine,
				&data->philos[i]))
			return (i);
		i++;
	}
	if (pthread_create(&data->monitor, NULL, monitor_routine, data))
		return (i);
	return (-1);
}

int	start_simulation(t_data *data)
{
	int	i;
	int	count;

	data->start_time = get_time() + 100;
	count = spawn_threads(data);
	if (count != -1)
	{
		i = 0;
		while (i < count)
			pthread_join(data->philos[i++].thread, NULL);
		return (1);
	}
	i = 0;
	while (i < data->nb_philos)
		pthread_join(data->philos[i++].thread, NULL);
	pthread_join(data->monitor, NULL);
	return (0);
}
