/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:01:08 by briandri          #+#    #+#             */
/*   Updated: 2026/01/03 12:00:42 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

static int	grab_forks(t_philo *philo, pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	pthread_mutex_lock(f1);
	if (simulation_finished(philo->data))
	{
		pthread_mutex_unlock(f1);
		return (1);
	}
	print_status(philo, "has taken a fork");
	if (philo->data->nb_philos == 1)
	{
		ft_usleep(philo->data->time_to_die, philo->data);
		pthread_mutex_unlock(f1);
		return (1);
	}
	pthread_mutex_lock(f2);
	if (simulation_finished(philo->data))
	{
		pthread_mutex_unlock(f2);
		pthread_mutex_unlock(f1);
		return (1);
	}
	print_status(philo, "has taken a fork");
	return (0);
}

void	update_meal_data(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	print_status(philo, "is eating");
	ft_usleep(philo->data->time_to_eat, philo->data);
}

void	eat_routine(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	first = philo->left_fork;
	second = philo->right_fork;
	if (philo->id % 2 == 0)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	if (grab_forks(philo, first, second))
		return ;
	update_meal_data(philo);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
}
