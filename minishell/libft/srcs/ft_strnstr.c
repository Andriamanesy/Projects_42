/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:28:46 by briandri          #+#    #+#             */
/*   Updated: 2025/03/18 16:04:27 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char			*cast_1;
	char			*cast_2;
	unsigned int	i;
	unsigned int	j;

	cast_1 = (char *)big;
	cast_2 = (char *)little;
	i = 0;
	j = 0;
	if (!cast_2[0])
		return (cast_1);
	while (cast_1[i] && i < len)
	{
		while (cast_1[i + j] == cast_2[j] && (i + j) < len)
		{
			if (cast_2[j + 1] == '\0')
				return (&cast_1[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
