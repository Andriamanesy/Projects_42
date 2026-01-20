/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:40:58 by briandri          #+#    #+#             */
/*   Updated: 2026/01/18 03:12:27 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	init_philos(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_philos)
	{
		d->philos[i].id = i + 1;
		d->philos[i].meals_eaten = 0;
		d->philos[i].data = d;
		d->philos[i].left_fork = &d->forks[i];
		d->philos[i].right_fork = &d->forks[(i + 1) % d->nb_philos];
		i++;
	}
}

int	init_data(t_data *d)
{
	int	i;

	i = 0;
	d->forks = malloc(sizeof(pthread_mutex_t) * d->nb_philos);
	d->philos = malloc(sizeof(t_philo) * d->nb_philos);
	if (!d->forks || !d->philos)
		return (1);
	pthread_mutex_init(&d->print_lock, NULL);
	pthread_mutex_init(&d->meal_lock, NULL);
	pthread_mutex_init(&d->dead_lock, NULL);
	d->dead_flag = 0;
	while (i < d->nb_philos)
	{
		pthread_mutex_init(&d->forks[i], NULL);
		i++;
	}
	init_philos(d);
	return (0);
}
