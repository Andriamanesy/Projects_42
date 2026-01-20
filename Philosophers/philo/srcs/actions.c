/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:01:08 by briandri          #+#    #+#             */
/*   Updated: 2026/01/18 03:06:58 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

static int	take_forks(t_philo *p, pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	pthread_mutex_lock(f1);
	print_status(p, "has taken a fork");
	if (p->data->nb_philos == 1)
	{
		ft_usleep(p->data->time_to_die, p->data);
		pthread_mutex_unlock(f1);
		return (1);
	}
	if (simulation_finished(p->data))
	{
		pthread_mutex_unlock(f1);
		return (1);
	}
	pthread_mutex_lock(f2);
	print_status(p, "has taken a fork");
	if (simulation_finished(p->data))
	{
		pthread_mutex_unlock(f2);
		pthread_mutex_unlock(f1);
		return (1);
	}
	return (0);
}

void	eat_routine(t_philo *p)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (p->id % 2 == 0)
	{
		first = p->right_fork;
		second = p->left_fork;
	}
	else
	{
		first = p->left_fork;
		second = p->right_fork;
	}
	if (take_forks(p, first, second))
		return ;
	pthread_mutex_lock(&p->data->meal_lock);
	p->last_meal = get_time();
	p->meals_eaten++;
	pthread_mutex_unlock(&p->data->meal_lock);
	print_status(p, "is eating");
	ft_usleep(p->data->time_to_eat, p->data);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
}
