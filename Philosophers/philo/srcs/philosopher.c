/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:41:45 by briandri          #+#    #+#             */
/*   Updated: 2026/01/18 03:13:51 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

static void	synchronise_start(t_philo *p)
{
	while (get_time() < p->data->start_time)
		usleep(100);
	if (p->id % 2 == 0)
		ft_usleep(p->data->time_to_eat / 2, p->data);
}

static void	think_routine(t_philo *p)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	print_status(p, "is thinking");
	if (p->data->nb_philos % 2 == 0)
		return ;
	t_eat = p->data->time_to_eat;
	t_sleep = p->data->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.42, p->data);
}

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	synchronise_start(p);
	while (!simulation_finished(p->data))
	{
		if (p->data->nb_philos == 1)
		{
			print_status(p, "has taken a fork");
			ft_usleep(p->data->time_to_die, p->data);
			return (NULL);
		}
		eat_routine(p);
		print_status(p, "is sleeping");
		ft_usleep(p->data->time_to_sleep, p->data);
		think_routine(p);
	}
	return (NULL);
}
