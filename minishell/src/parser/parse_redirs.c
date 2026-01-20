/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:16 by briandri          #+#    #+#             */
/*   Updated: 2026/01/20 10:20:55 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	open_file(t_data *data, char *filename, int type)
{
	int	fd;

	fd = -2;
	if (type != HEREDOC && prepare_filename(data, &filename) == -1)
		return (-1);
	if (type == INPUT)
		fd = open(filename, O_RDONLY, 0644);
	else if (type == HEREDOC)
		fd = here_doc(data, filename);
	else if (type == TRUNC)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEND)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (type != HEREDOC && fd < 0)
		perror(filename);
	if (type != HEREDOC)
		free(filename);
	return (fd);
}

static int	get_in(t_data *data, t_token *tmp, t_cmd *cmd)
{
	if (tmp->type == INPUT || tmp->type == HEREDOC)
	{
		check_in_redirection(data, tmp, cmd);
		if (open_in_redirection(data, tmp, cmd) == 0)
			return (0);
	}
	return (1);
}

int	get_infile(t_data *data, t_token *token, t_cmd *cmd)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != PIPE && !get_in(data, tmp, cmd))
		return (0);
	if (tmp->type == PIPE)
		return (1);
	tmp = tmp->next;
	while (tmp->type != PIPE && tmp != data->token)
	{
		if (get_in(data, tmp, cmd) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	get_out(t_token *tmp, t_cmd *cmd, t_data *data)
{
	if (tmp->type == TRUNC || tmp->type == APPEND)
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		if (tmp->next == data->token || tmp->next->type == PIPE
			|| tmp->next->type <= 5)
		{
			if (cmd->redir_error == false)
			{
				ft_putendl_fd("minishell: ambiguous redirect", 2);
				return (0);
			}
			cmd->redir_error = true;
			return (1);
		}
		if (cmd->redir_error == false)
		{
			cmd->outfile = open_file(data, tmp->next->str, tmp->type);
			if (cmd->outfile == -1)
				return (cmd->redir_error = true, 0);
		}
	}
	return (1);
}

int	get_outfile(t_token *token, t_cmd *cmd, t_data *data)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != PIPE && !get_out(tmp, cmd, data))
		return (0);
	tmp = tmp->next;
	while (tmp != data->token && tmp->type != PIPE)
	{
		if (!get_out(tmp, cmd, data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
