/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:37:06 by briandri          #+#    #+#             */
/*   Updated: 2025/03/18 16:00:53 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*cst_1;
	unsigned char	*cst_2;

	i = 0;
	cst_1 = (unsigned char *)s1;
	cst_2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*cst_1 != *cst_2)
			return ((*cst_1) - (*cst_2));
		cst_1++;
		cst_2++;
		i++;
	}
	return (0);
}
