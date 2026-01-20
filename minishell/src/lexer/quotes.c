/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:58 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 16:57:33 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	quoting_choice(bool *dq, bool *sq, int *index, char c)
{
	if ((c == '\'' || c == '"') && !*sq && !*dq)
	{
		if (c == '\'' && !*dq)
			*sq = true;
		else if (c == '"' && !*sq)
			*dq = true;
		if (index)
			++(*index);
	}
	else if ((c == '\'' || c == '"'))
	{
		if (c == '\'' && !*dq && *sq)
			*sq = false;
		else if (c == '"' && !*sq && *dq)
			*dq = false;
		if (index)
			++(*index);
	}
}

int	check_open_quote(t_data *data, char *line)
{
	bool	dq;
	bool	sq;
	int		i;

	i = 0;
	dq = false;
	sq = false;
	while (line && line[i])
	{
		quoting_choice(&dq, &sq, &i, line[i]);
		if (line[i] && line[i] != '\'' && line[i] != '"')
			++i;
	}
	if (dq || sq)
	{
		print_error("open quote\n");
		data->exit_code = 2;
		return (1);
	}
	return (0);
}

int	count_quote(char *str)
{
	int		i;
	int		count;
	char	quote;

	quote = 0;
	i = 0;
	count = 0;
	while (str && str[i + count])
	{
		if (str[i + count] == 30 || str[i + count] == 31)
			quote = str[count + i++];
		while (quote != 0)
		{
			if (str[i + count] == quote)
			{
				i++;
				break ;
			}
			count++;
		}
		if (quote == 0 && str[i + count])
			count++;
		quote = 0;
	}
	return (count);
}

char	*rm_quote(char *dst, char *src)
{
	int		i;
	int		j;
	char	quote;

	quote = 0;
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == 30 || src[i] == 31)
			quote = src[i++];
		while (quote != 0)
		{
			if (src[i] == quote)
			{
				i++;
				break ;
			}
			dst[j++] = src[i++];
		}
		if (quote == 0 && src[i])
			dst[j++] = src[i++];
		quote = 0;
	}
	return (dst[j] = '\0', dst);
}

void	open_quote(char **str)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	while (str[i])
	{
		len = count_quote(str[i]);
		tmp = str[i];
		str[i] = malloc(sizeof(char) * (len + 1));
		rm_quote(str[i], tmp);
		free(tmp);
		i++;
	}
}
