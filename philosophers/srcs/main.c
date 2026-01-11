/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 08:44:26 by briandri          #+#    #+#             */
/*   Updated: 2026/01/03 08:44:35 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("Error: Wrong arguments\n"), 1);
	if (parse_args(&data, ac, av))
		return (1);
	if (init_data(&data))
		return (1);
	if (start_simulation(&data))
		return (1);
	cleanup(&data);
	return (0);
}
