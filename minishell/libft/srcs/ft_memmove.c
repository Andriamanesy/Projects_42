/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:07:53 by briandri          #+#    #+#             */
/*   Updated: 2025/03/18 17:07:49 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	tmp[1024];

	s = (char *)src;
	if (!dest && !s)
		return (0);
	if (n <= 1024)
	{
		ft_memcpy(tmp, s, n);
		ft_memcpy(dest, tmp, n);
	}
	return (dest);
}
