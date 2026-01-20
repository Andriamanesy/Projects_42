/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:03:22 by briandri          #+#    #+#             */
/*   Updated: 2026/01/18 01:53:02 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	cleanup(t_data *d)
{
	int	i;

	if (d->forks)
	{
		i = 0;
		while (i < d->nb_philos)
			pthread_mutex_destroy(&d->forks[i++]);
		free(d->forks);
	}
	pthread_mutex_destroy(&d->print_lock);
	pthread_mutex_destroy(&d->meal_lock);
	pthread_mutex_destroy(&d->dead_lock);
	if (d->philos)
		free(d->philos);
}
