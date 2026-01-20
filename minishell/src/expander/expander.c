/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:47:23 by briandri          #+#    #+#             */
/*   Updated: 2026/01/17 15:22:34 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	should_expand(char next_char)
{
	if (!next_char)
		return (0);
	if (ft_isalnum(next_char) || next_char == '?' || next_char == '_')
		return (1);
	return (0);
}

static int	is_quote(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == 30)
			count++;
		else if (str[i] == 31)
			return (1);
		i++;
	}
	if (count == 2)
		return (0);
	return (1);
}

static int	process_char(char **line, int *i, char **str, t_data *data)
{
	if (is_quote(*line) && (*line)[*i] == '$'
		&& !data->sq && should_expand((*line)[*i + 1]))
	{
		if (!add_dollar((*line), i, str, data))
			return (0);
	}
	else
	{
		if (!add_char(&(*line)[*i], str, data, i))
			return (0);
	}
	return (1);
}

int	replace_dollar(char **line, t_data *data, int redir)
{
	char	*str;
	bool	dq;
	int		i;

	i = 0;
	dq = false;
	data->sq = false;
	str = ft_strdup("");
	if (!str)
		return (0);
	while ((*line)[i])
	{
		if (!process_char(line, &i, &str, data))
			return (0);
	}
	if (redir == 0)
		free(*line);
	*line = str;
	return (1);
}
