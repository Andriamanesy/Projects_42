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

#include "minishell.h"

int	len_word(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (is_space(str[i]))
		i++;
	while (str[i])
	{
		if ((str[i] == 30 || str[i] == 31))
		{
			if (quote == 0)
				quote = str[i];
			else if (quote == str[i])
				quote = 0;
		}
		else if (is_space(str[i]) && quote == 0)
			break ;
		i++;
	}
	return (i);
}

static int	skip_quotes(char const *str, int i)
{
	char	quote;

	quote = str[i++];
	while (str[i] && str[i] != quote)
		i++;
	if (str[i])
		i++;
	return (i);
}

int	ft_count_words(char const *str)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (!str[i])
			break ;
		count++;
		while (str[i] && !is_space(str[i]))
		{
			if (str[i] == 30 || str[i] == 31)
				i = skip_quotes(str, i);
			else
				i++;
		}
	}
	return (count);
}

char	**ft_split_quotes(char *s)
{
	char	**tab;
	int		i;
	int		len;

	tab = malloc(sizeof(char *) * (ft_count_words(s) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (is_space(*s))
			s++;
		if (*s)
		{
			len = len_word(s);
			tab[i] = ft_substr(s, 0, len);
			if (!tab[i])
				return (NULL);
			i++;
			s += len;
		}
	}
	tab[i] = NULL;
	return (tab);
}
