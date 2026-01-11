/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:14:37 by briandri          #+#    #+#             */
/*   Updated: 2025/03/09 11:24:43 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cast_s;
	size_t	i;
	char	*new_string;
	size_t	len_s;

	cast_s = (char *)s;
	i = 0;
	if (cast_s == NULL)
		return (NULL);
	len_s = ft_strlen(cast_s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > (len_s - start))
		len = len_s - start;
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (new_string == NULL)
		return (NULL);
	while (i < len && cast_s[start + i])
	{
		new_string[i] = cast_s[i + start];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
