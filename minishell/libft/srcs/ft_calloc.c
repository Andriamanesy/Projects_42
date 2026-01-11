/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:29:54 by briandri          #+#    #+#             */
/*   Updated: 2025/03/18 15:58:16 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memoire;
	size_t			i;

	if (nmemb == 0 || size == 0)
		i = 0;
	else
	{
		if ((nmemb) > SIZE_MAX / size)
			return (NULL);
		i = nmemb * size;
	}
	memoire = malloc(i);
	if (memoire == NULL)
		return (NULL);
	if (i != 0)
		ft_bzero(memoire, i);
	return (memoire);
}
