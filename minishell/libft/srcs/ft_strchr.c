/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:41:37 by briandri          #+#    #+#             */
/*   Updated: 2025/03/18 16:02:43 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*cast_s;

	index = 0;
	cast_s = (char *)s;
	while (cast_s[index] && cast_s[index] != (char)c)
		index++;
	if (cast_s[index] == (char)c)
		return (&cast_s[index]);
	return (0);
}
