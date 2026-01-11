/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 07:51:05 by briandri          #+#    #+#             */
/*   Updated: 2025/03/18 16:07:55 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	i;
	size_t	first;
	size_t	last;

	first = 0;
	while (s1[first] && ft_set(s1[first], set))
		first++;
	last = ft_strlen(s1);
	while (last > first && ft_set(s1[last - 1], set))
		last--;
	new_str = (char *)malloc(sizeof(*s1) * (last - first + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (first < last)
		new_str[i++] = s1[first++];
	new_str[i] = 0;
	return (new_str);
}

static int	ft_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
