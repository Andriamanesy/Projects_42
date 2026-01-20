/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:29:41 by briandri          #+#    #+#             */
/*   Updated: 2026/01/20 10:20:52 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	fill_cmd(t_data *data, t_token *tmp)
{
	if (!handle_infile(data, tmp))
		return (0);
	if (!handle_outfile(data, tmp))
		return (0);
	return (handle_cmd_param(data, tmp));
}

int	norm(t_data *data, t_token *tmp)
{
	if (!append_cmd(&data->cmd, -2, -2, NULL))
		free_all(data, ERR_MALLOC, EXT_MALLOC);
	if (!fill_cmd(data, tmp))
	{
		data->exit_code = 1;
		return (0);
	}
	return (1);
}

int	check_in_redirection(t_data *data, t_token *tmp, t_cmd *cmd)
{
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (tmp->next == data->token || tmp->next->type == PIPE
		|| tmp->next->type <= 5)
	{
		if (cmd->redir_error == false)
			ft_putendl_fd("minishell: syntax error", 2);
		cmd->redir_error = true;
		return (1);
	}
	return (1);
}

int	open_in_redirection(t_data *data, t_token *tmp, t_cmd *cmd)
{
	int	type;

	if (tmp->type == INPUT)
		type = INPUT;
	else
		type = HEREDOC;
	if (cmd->redir_error == false)
	{
		cmd->infile = open_file(data, tmp->next->str, type);
		if (cmd->infile == -1)
		{
			cmd->redir_error = true;
			return (0);
		}
	}
	return (1);
}

int	prepare_filename(t_data *data, char **filename)
{
	char	*tmp;

	quote_to_ascii(*filename);
	replace_dollar(filename, data, 1);
	if ((*filename)[0] == 0)
	{
		free(*filename);
		*filename = NULL;
		ft_putstr_fd("minishell: ambiguous redirect\n", 2);
		return (-1);
	}
	tmp = malloc(sizeof(char) * (count_quote(*filename) + 1));
	rm_quote(tmp, *filename);
	free(*filename);
	*filename = tmp;
	return (0);
}
