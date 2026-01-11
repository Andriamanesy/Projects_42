/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:41:45 by briandri          #+#    #+#             */
/*   Updated: 2026/01/03 11:15:56 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_time() < philo->data->start_time)
		usleep(100);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2, philo->data);
	while (!simulation_finished(philo->data))
	{
		eat_routine(philo);
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
		think_routine(philo);
	}
	return (NULL);
}

int	start_threads(t_data *data)
{
	int	i;

	data->start_time = get_time();
	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				&data->philos[i]))
			return (1);
	}
	monitor_routine(data);
	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philos[i].thread, NULL);
	return (0);
}

void	think_routine(t_philo *philo)
{
	long	time_to_think;

	print_status(philo, "is thinking");
	if (philo->data->nb_philos % 2 == 0)
		return ;
	time_to_think = (philo->data->time_to_die - philo->data->time_to_eat
			- philo->data->time_to_sleep) / 2;
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think > 603)
		time_to_think = 200;
	ft_usleep(time_to_think * 0.33, philo->data);
}
