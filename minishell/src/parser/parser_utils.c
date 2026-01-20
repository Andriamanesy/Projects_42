/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:44:43 by briandri          #+#    #+#             */
/*   Updated: 2026/01/17 13:59:18 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	pipe_syntax_error(t_data *data)
{
	write(2, "syntax error near unexpected token '|'\n", 39);
	data->exit_code = 2;
	free_token(&data->token);
	free_cmd(&data->cmd);
	return (0);
}

static int	validate_pipes(t_data *data)
{
	t_token	*tmp;
	int		first_pass;

	tmp = data->token;
	first_pass = 1;
	while (tmp && (first_pass || tmp != data->token))
	{
		first_pass = 0;
		if (tmp->type == PIPE)
		{
			if (!tmp->next || tmp->next->type == PIPE)
				return (pipe_syntax_error(data));
		}
		if (tmp->next == data->token && tmp->type == PIPE)
			return (pipe_syntax_error(data));
		tmp = tmp->next;
	}
	return (1);
}

int	check_pipe(t_data *data)
{
	if (data->token && data->token->type == PIPE)
		return (pipe_syntax_error(data));
	return (validate_pipes(data));
}

int	count_heredoc(t_data *data)
{
	t_token	*tmp;
	int		count;

	count = 0;
	tmp = data->token;
	tmp = tmp->next;
	while (tmp != data->token)
	{
		if (tmp->prev->type == HEREDOC)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	count_pipe(t_data *data)
{
	t_token	*tmp;
	int		count;

	count = 0;
	tmp = data->token;
	tmp = tmp->next;
	while (tmp != data->token)
	{
		if (tmp->prev->type == PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
