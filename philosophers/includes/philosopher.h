/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 08:45:06 by briandri          #+#    #+#             */
/*   Updated: 2026/01/03 08:45:09 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nb_meals;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
}					t_data;

long				get_time(void);
int					parse_args(t_data *data, int argc, char **argv);
int					init_data(t_data *data);
void				print_status(t_philo *philo, char *status);
void				*philo_routine(void *arg);
int					start_threads(t_data *data);
void				eat_routine(t_philo *philo);
void				ft_usleep(long time_in_ms, t_data *data);
int					check_death(t_data *data);
int					simulation_finished(t_data *data);
int					start_simulation(t_data *data);
int					all_philos_fed(t_data *data);
void				cleanup(t_data *data);
void				think_routine(t_philo *philo);
void				*monitor_routine(void *arg);
int					is_dead(t_philo *philo);
void				print_death(t_philo *philo);

#endif
