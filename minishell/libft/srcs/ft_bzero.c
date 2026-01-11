/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:38:14 by briandri          #+#    #+#             */
/*   Updated: 2025/03/05 00:35:40 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*zero;
	unsigned int	index;

	zero = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		zero[index] = '\0';
		index++;
	}
}
