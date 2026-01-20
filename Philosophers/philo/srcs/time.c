/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:41:53 by briandri          #+#    #+#             */
/*   Updated: 2026/01/18 01:29:12 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"
#include <sys/time.h>

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long ms, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time();
	while (!simulation_finished(data))
	{
		elapsed = get_time() - start;
		if (elapsed >= ms)
			break ;
		rem = ms - elapsed;
		if (rem > 1)
			usleep(rem / 2 * 1000);
		else
			while (get_time() - start < ms)
				;
	}
}
