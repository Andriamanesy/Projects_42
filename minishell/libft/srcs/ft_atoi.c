/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:10:04 by briandri          #+#    #+#             */
/*   Updated: 2025/03/05 03:16:21 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nprtr)
{
	int	i;
	int	sign;
	int	result;
	int	cmpt;

	sign = 1;
	i = 0;
	result = 0;
	cmpt = 0;
	while (nprtr[i] == 32 || (nprtr[i] >= 9 && nprtr[i] <= 13))
		i++;
	while (nprtr[i] == '-' || nprtr[i] == '+')
	{
		if (nprtr[i] == '-')
			sign *= -1;
		cmpt++;
		if (cmpt > 1)
			return (0);
		i++;
	}
	while (nprtr[i] >= 48 && nprtr[i] <= 57)
		result = result * 10 + (nprtr[i++] - '0');
	return (result * sign);
}
