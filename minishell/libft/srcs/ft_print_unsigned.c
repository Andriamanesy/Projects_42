/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:51:04 by briandri          #+#    #+#             */
/*   Updated: 2025/04/22 18:30:46 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len_unsigned(unsigned int nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int nb)
{
	unsigned int	nbr;

	nbr = ft_len_unsigned(nb);
	if (nb > 9)
	{
		ft_print_unsigned(nb / 10);
		ft_print_unsigned(nb % 10);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
	}
	return (nbr);
}
