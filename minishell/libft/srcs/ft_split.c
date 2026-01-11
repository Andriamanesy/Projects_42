/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:16:18 by briandri          #+#    #+#             */
/*   Updated: 2025/03/19 10:20:02 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_words(char const *str, char c);

char	**ft_split(char const *str, char c)
{
	char	**new_tab;
	size_t	len;
	int		i;

	new_tab = (char **)malloc((ft_count_words(str, c) + 1) * sizeof(char *));
	if (!new_tab || !str)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				len = ft_strlen(str);
			else
				len = ft_strchr(str, c) - str;
			new_tab[i++] = ft_substr(str, 0, len);
			str += len;
		}
	}
	new_tab[i] = NULL;
	return (new_tab);
}

static int	ft_count_words(char const *str, char c)
{
	int	count_wd;

	if (!*str)
		return (0);
	count_wd = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count_wd++;
		while (*str != c && *str)
			str++;
	}
	return (count_wd);
}
