/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:25 by briandri          #+#    #+#             */
/*   Updated: 2026/01/17 13:50:06 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	create_list_cmd(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	if (!norm(data, tmp))
		return (0);
	tmp = tmp->next;
	while (tmp != data->token)
	{
		if (tmp->prev->type == PIPE)
		{
			if (!norm(data, tmp))
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	expand_function(t_data *data)
{
	int		i;
	t_cmd	*cmd;

	i = 0;
	cmd = data->cmd;
	if (data->cmd->cmd_param[0] == NULL)
		return (1);
	while (data->cmd != cmd || i == 0)
	{
		i = 0;
		while (data->cmd->cmd_param[i])
		{
			replace_dollar(&data->cmd->cmd_param[i], data, 0);
			i++;
		}
		data->cmd = data->cmd->next;
	}
	return (1);
}

static int	parsing(t_data *data, char *line)
{
	if (check_open_quote(data, line) == 1)
		return (free(line), 0);
	if (!create_list_token(&data->token, line))
	{
		free (line);
		free_all(data, ERR_MALLOC, EXT_MALLOC);
	}
	if (check_pipe(data) == 0)
		return (0);
	if (count_heredoc(data) > 16)
	{
		free (line);
		free_all(data, "maximum here-document count exceeded\n", 2);
	}
	if (count_pipe(data) >= 3333)
	{
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		data->exit_code = 2;
		return (0);
	}
	free(line);
	return (1);
}

int	parseline(t_data *data, char *line)
{
	if (parsing(data, line) == 0)
		return (0);
	if (!data->token || !create_list_cmd(data))
	{
		free_token(&data->token);
		return (free_cmd(&data->cmd), 0);
	}
	free_token(&data->token);
	transform_quote(data);
	expand_function(data);
	data->cmd->cmd_param = function_split(data->cmd->cmd_param);
	function_quote(data);
	return (1);
}
