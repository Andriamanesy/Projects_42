/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:13:08 by briandri          #+#    #+#             */
/*   Updated: 2025/03/19 10:19:17 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	extension(int *i, char *c, long *nbr)
{
	if (*nbr < 0)
	{
		(*nbr) *= -1;
		*c = '-';
		(*i) += 1;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*dst;
	int		cmpt;
	int		fin;
	long	nbr;

	i = 0;
	nbr = n;
	cmpt = count(nbr);
	if (cmpt == 0 || nbr < 0)
		cmpt++;
	fin = cmpt;
	dst = malloc(sizeof(char) * cmpt + 1);
	if (!dst)
		return (NULL);
	extension(&i, &dst[0], &nbr);
	while (cmpt > i)
	{
		cmpt--;
		dst[cmpt] = (nbr % 10) + '0';
		nbr /= 10;
	}
	dst[fin] = '\0';
	return (dst);
}
