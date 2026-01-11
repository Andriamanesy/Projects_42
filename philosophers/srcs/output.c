/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:41:24 by briandri          #+#    #+#             */
/*   Updated: 2026/01/03 11:14:56 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead_flag)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return ;
	}
	printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id,
		status);
	pthread_mutex_unlock(&philo->data->dead_lock);
}
