/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:26:25 by briandri          #+#    #+#             */
/*   Updated: 2025/04/22 22:27:39 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len_hex(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len ++;
		nbr = nbr / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int nbr, const char f)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16, f);
		ft_put_hex(nbr % 16, f);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
		{
			if (f == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), 1);
			else if (f == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int nbr, const char f)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(nbr, f);
	return (ft_len_hex(nbr));
}
