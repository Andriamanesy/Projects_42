/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:35:12 by harramar          #+#    #+#             */
/*   Updated: 2026/01/17 15:20:57 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**function_split(char **av)
{
	int		i;
	int		j;
	int		len;
	char	**res;
	char	**tmp;

	i = -1;
	len = 0;
	while (av[++i])
		len += ft_count_words(av[i]);
	res = ft_calloc(sizeof(char *), len + 1);
	res[len] = NULL;
	i = -1;
	len = 0;
	while (av[++i])
	{
		j = 0;
		tmp = ft_split_quotes(av[i]);
		if (!tmp)
			return (NULL);
		while (tmp[j])
			res[len++] = tmp[j++];
		free(tmp);
	}
	return (free_cmd_param(av), res);
}

void	quote_to_ascii(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str && str[i])
	{
		if (quote == 0 && (str[i] == '\'' || str[i] == '"'))
		{
			quote = str[i];
			if (str[i] == '\'')
				str[i] = 30;
			else
				str[i] = 31;
		}
		else if (quote != 0 && str[i] == quote)
		{
			if (str[i] == '\'')
				str[i] = 30;
			else
				str[i] = 31;
			quote = 0;
		}
		i++;
	}
}

void	function_quote(t_data *data)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	cmd = data->cmd;
	while (data->cmd != cmd || i == 0)
	{
		open_quote(data->cmd->cmd_param);
		data->cmd = data->cmd->next;
		i++;
	}
}

void	transform_quote(t_data *data)
{
	t_cmd	*cmd;
	int		i;
	int		j;

	i = 0;
	cmd = data->cmd;
	while (data->cmd != cmd || i == 0)
	{
		j = 0;
		while (data->cmd->cmd_param[j])
			quote_to_ascii(data->cmd->cmd_param[j++]);
		data->cmd = data->cmd->next;
		i++;
	}
}
