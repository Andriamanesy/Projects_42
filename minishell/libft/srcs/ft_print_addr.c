/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:23:33 by briandri          #+#    #+#             */
/*   Updated: 2025/04/22 18:28:48 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len_addr(uintptr_t nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

static void	ft_put_address(uintptr_t nbr)
{
	if (nbr >= 16)
	{
		ft_put_address(nbr / 16);
		ft_put_address(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int	ft_print_addr(uintptr_t addr)
{
	int	print_len;

	print_len = 0;
	if (addr == 0)
		print_len = write(1, "(nil)", 5);
	else
	{
		print_len += write(1, "0x", 2);
		ft_put_address(addr);
		print_len += ft_len_addr(addr);
	}
	return (print_len);
}
