/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 08:45:06 by briandri          #+#    #+#             */
/*   Updated: 2026/01/18 03:29:31 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	long				last_meal;
	int					meals_eaten;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					nb_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					nb_meals;
	long				start_time;
	int					dead_flag;

	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		dead_lock;

	t_philo				*philos;
	pthread_t			monitor;
}						t_data;

int						parse_args(t_data *data, int ac, char **av);
int						init_data(t_data *data);
void					init_philos(t_data *data);

int						start_simulation(t_data *data);
int						simulation_finished(t_data *data);

void					*philo_routine(void *arg);
void					*monitor_routine(void *arg);
void					eat_routine(t_philo *philo);

long					get_time(void);
void					ft_usleep(long ms, t_data *data);
void					print_status(t_philo *philo, char *msg);
void					cleanup(t_data *data);

#endif